#!/bin/bash
FILE=bin/Debug/QueueAndStack

if [ -f $FILE ]; then
    valgrind --leak-check=full $FILE
else
    echo "Could not find binary file. Have you built the project?"
fi
read
