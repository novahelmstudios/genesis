#/!/bin/bash

set -e

echo "[BUILD] Building window test module"

ENGINE_INC="-Iengine/inc -Iengine/inc/external -I/usr/include/freetype2 -I/usr/include/stb"
ENGINE_SRC="engine/src/window_manager/window.cpp engine/src/glad.c"
TEST_SRC="test/window.cpp"
LIBS="-lglfw -lGL -ldl -lpthread -lm"
OUT="build/test/window_test"

mkdir -p build/test

g++ -std=c++23 $ENGINE_INC -Wall -Wextra $TEST_SRC $ENGINE_SRC $LIBS -o $OUT

echo "[RUN] Executing test..."
$OUT
