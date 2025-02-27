#!/usr/bin/bash

# 读取命令行参数作为变量num
num=$1
if [ -f ans/$num.cpp ]; then
    echo "File already exists."
else
    cat templates/template.cpp > ans/$num.cpp
fi