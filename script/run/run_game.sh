#!/bin/bash

set -e

echo "[BUILD] Compiling game with engine..."

INCLUDES="-Iengine/inc -Iengine/inc/external -I/usr/include/freetype2 -I/usr/include/stb"
ENGINE_SOURCES=$(find engine/src -name "*.cpp")
ENGINE_SOURCES+=" engine/src/glad.c"
GAME_SRC="game/main.cpp"
OUT="build/game"
LIBS="-lglfw -lGL -ldl -lpthread -lm"

mkdir -p build/game

g++ -std=c++23 $INCLUDES -Wall -Wextra $GAME_SRC $ENGINE_SOURCES $LIBS -o $OUT

echo "[RUN] Launching game..."
$OUT

