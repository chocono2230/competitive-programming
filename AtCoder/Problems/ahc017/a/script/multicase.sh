#!/bin/bash
set -e

if [ $# != 2 ]; then
    echo 引数エラー: $*
    exit 1
fi
sz=$1
lim=$((sz-1))
echo $sz $lim
wdir=sh_work

rm -rf $wdir
mkdir $wdir

z=`pwd`/make_random.cpp
o=`pwd`/$wdir
g++ -std=gnu++17 -I /home/chomonolis/libs/ac-library/ -Wall -Wextra -O2 $z -o $o/a.out
ot=/$o/a.out

p=$RANDOM
$ot $p $sz > ./$wdir/seed.txt
outdir=`pwd`/$wdir
cd ./tools
cargo run --release --bin gen ../$wdir/seed.txt --dir=$outdir
cd ..

z=`pwd`/$2
g++ -std=gnu++17 -I /home/chomonolis/libs/ac-library/ -Wall -Wextra -O2 $z -o $o/a.out
ot=/$o/a.out

sum=0

function tt() {
  wdir=sh_work
  nn=$(printf "%04d" $1).txt
  ss=`pwd`/${wdir}/$nn
  echo $nn
  oo=`pwd`/${wdir}/$(printf "%04d" $1)_out.txt
  ot=`pwd`/$wdir/a.out
  cat $ss | $ot 1> /dev/null 2> $oo
}
export -f tt

seq 0 $lim | xargs -P 5 -I {} bash -c "tt {}"
ex=0
for ((i=0; i < $sz; i++)); do
  oo=`pwd`/${wdir}/$(printf "%04d" $i)_out.txt
  x=`sed -n 15p $oo`
  if [ $x != "0" ]; then
    ex=$((ex + 1))
    continue
  fi
  d=`tail -n 1 $oo`
  sum=$((sum + d))
done
echo $sum
echo $ex
tt=$((sz - ex))
sum=$((sum * 50 / tt))
echo $sum