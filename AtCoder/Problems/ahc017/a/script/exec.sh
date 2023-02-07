#!/bin/bash
set -e

if [ $# != 1 ]; then
    echo 引数エラー: $#
    exit 1
fi

f=./tools/in/$(printf "%04d" $1).txt
head -n 1 $f
cat $f > ./in.txt
z=`pwd`/p1.cpp
g++ -std=gnu++17 -I /home/chomonolis/libs/ac-library/ -Wall -Wextra -O2 $z
cat ./in.txt | ./a.out > out.txt
echo "============================"
# z=`pwd`/p2.cpp
# g++ -std=gnu++17 -I /home/chomonolis/libs/ac-library/ -Wall -Wextra -O2 $z
# cat ./in.txt | ./a.out > out.txt
# echo "============================"
z=`pwd`/ahc017_a.cpp
g++ -std=gnu++17 -I /home/chomonolis/libs/ac-library/ -Wall -Wextra -O2 $z
cat ./in.txt | ./a.out > out.txt