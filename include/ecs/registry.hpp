#pragma once

#include "component.hpp"
#include "entity.hpp"

#include <cassert>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

namespace Engine {

template <typename... Args> struct first_type;

template <typename T, typename... Args> struct first_type<T, Args...> {
  using type = T;
};

template <typename... Args> using first_t = typename first_type<Args...>::type;

class registry {
public:
  /*
   * Generates a unique EntityID
   * and adds it to the alive set
   */
  Entity Create() {
    EntityID id = next_id++;
    alive.insert(id);
    return Entity{id};
  }

  /*
   * for every registered component pools
   * remove that entity's component (if any)
   */
  void Destroy(Entity e) {
    for (auto &[_, pool] : pools)
      pool->remove(e.id);
    alive.erase(e.id);
  }

  /*
   * gets or creates the component pool for type T
   * reg.Add<Position>(e, 1.0f, 2.0f);
   */
  template <typename T, typename... Args> void Add(Entity e, Args &&...args) {
    auto &pool = Get_CreatePool<T>();
    pool.insert(e.id, std::forward<Args>(args)...);
  }

  /*
   * returns a reference to the component T associated with the entity
   */
  template <typename T> T &Get(Entity e) {
    auto &pool = GetPool<T>();
    return pool.get(e.id);
  }

  /*
   * returns a vector that has all the entities
   * that have the requested components
   *
   * for e.g: reg.View<Transform, Animator, Collider>();
   *
   * it itterates over all entities with Transform component
   * and for each checks if it has Animator and Collider
   * components and return only those
   */
  template <typename... T> std::vector<Entity> View() {
    std::vector<Entity> result;

    auto &pool = GetPool<first_t<T...>>(); // Correct portable version

    for (const auto &[id, _] : pool.components) {
      Entity e{id};

      if ((Has<T>(e) && ...)) // check Has<T1>(e) && Has<T2>(e) && ...
        result.push_back(e);
    }

    return result;
  }

  /*
   * Looks up the component for type T
   * checks if the entity has a component
   * of that type
   */
  template <typename T> bool Has(Entity e) const {
    auto it = pools.find(GetComponentTypeID<T>());
    if (it == pools.end())
      return false;
    auto *pool = static_cast<component_pool<T> *>(it->second.get());
    return pool->has(e.id);
  }

  /*
   * removes a component T from the entity e
   */
  template <typename T> void Remove(Entity e) {
    auto &pool = GetPool<T>();
    pool.remove(e.id);
  }

private:
  /*
   * Abstract base class for all component pools
   * Ensures that all component pools can be
   * stored in the same map
   */
  struct icomponent_pool {
    virtual ~icomponent_pool() = default;
    virtual void remove(EntityID id) = 0;
  };

  template <typename T> struct component_pool : icomponent_pool {
    std::unordered_map<EntityID, T> components;

    void insert(EntityID id, T &&c) { components.emplace(id, std::move(c)); }

    template <typename... Args> void insert(EntityID id, Args &&...args) {
      components.emplace(id, T(std::forward<Args>(args)...));
    }

    T &get(EntityID id) {
      assert(components.count(id));
      return components.at(id);
    }

    bool has(EntityID id) const { return components.count(id) > 0; }

    void remove(EntityID id) override { components.erase(id); }
  };

  /*
   * Checks if a component pool for T exists
   * if not then creates a pool
   */
  template <typename T> component_pool<T> &Get_CreatePool() {
    ComponentTypeID id = GetComponentTypeID<T>();
    if (!pools.count(id))
      pools[id] = std::make_unique<component_pool<T>>();
    return *static_cast<component_pool<T> *>(pools[id].get());
  }

  /*
   * gets the component pool for the T
   * Asserts if pool doesn't exist
   */
  template <typename T> component_pool<T> &GetPool() {
    ComponentTypeID id = GetComponentTypeID<T>();
    assert(pools.count(id));
    return *static_cast<component_pool<T> *>(pools.at(id).get());
  }

  EntityID next_id = 0;               /* counter for assigning unique ID */
  std::unordered_set<EntityID> alive; /* set of currently active entity ID  */
  std::unordered_map<ComponentTypeID, std::unique_ptr<icomponent_pool>>
      pools; /* maps ComponentTypeID -> polymorphic component pool  */
};

} // namespace Engine
