#!/bin/bash
set -e

if [ $# -lt 1 ]; then
    echo 引数エラー: $#
    echo \<test_case_number\> \<code\> \<code\> ...
    exit 1
fi

f=./sh_input/$(printf "%04d" $1).txt
head -n 1 $f
cat $f > ./in.txt


for ((i=2; i <= $#; i++)); do
    z=`pwd`/${!i}
    echo ${!i}
    g++ -std=gnu++17 -Wall -Wextra -O2 -DCHOMONOLIS_LOCAL -DCHOCONO_LOCAL $z
    cat ./in.txt | ./a.out > output.txt
done
