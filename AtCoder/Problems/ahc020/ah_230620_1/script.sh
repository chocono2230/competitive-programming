#!/bin/bash
set -e

if [ $# != 1 ]; then
    echo 引数エラー: $#
    exit 1
fi

f=./tools/in/$(printf "%04d" $1).txt
head -n 1 $f
cat $f > ./in.txt

z=`pwd`/past/v1.cpp
g++ -std=gnu++17 -Wall -Wextra -O2 -DCHOMONOLIS_LOCAL -DCHOCONO_LOCAL $z
cat ./in.txt | ./a.out > output.txt

z=`pwd`/ahc020_ah_230620_1.cpp
g++ -std=gnu++17 -Wall -Wextra -O2 -DCHOMONOLIS_LOCAL -DCHOCONO_LOCAL $z
cat ./in.txt | ./a.out > output.txt