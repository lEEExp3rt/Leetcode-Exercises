#!/usr/bin/bash

num=$1
if [ -z $num ]; then
    echo "Please input the number of the problem."
    exit 1
fi
if [ -f ans/$num.cpp ]; then
    echo "File already exists."
else
    cat templates/template.cpp > ans/$num.cpp
    code README.md
    code ans/$num.cpp
fi