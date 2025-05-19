#!/bin/bash

SRC=${1:-test.c}
OUT_DIR="source/output"
OUT_FILE="$OUT_DIR/main.out"

mkdir -p $OUT_DIR

gcc -Wall -g "$SRC" -o "$OUT_FILE" -lGL -lGLU -lglut -lm

if [ $? -eq 0 ]; then
    echo "Compiled successfully."
    ./"$OUT_FILE"
else
    echo "Compilation failed."
fi
