#!/bin/bash
set -e

if [ $# != 1 ]; then
    echo 引数エラー: $#
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

z=`pwd`/sub_50.cpp
g++ -std=gnu++17 -I /home/chomonolis/libs/ac-library/ -Wall -Wextra -O2 $z -o $o/a50.out
ot2=/$o/a50.out

z=`pwd`/sub_100.cpp
g++ -std=gnu++17 -I /home/chomonolis/libs/ac-library/ -Wall -Wextra -O2 $z -o $o/a100.out
ot3=/$o/a100.out

function tt() {
  wdir=sh_work
  nn=$(printf "%04d" $1).txt
  ss=`pwd`/${wdir}/$nn
  echo $nn
  oo=`pwd`/${wdir}/$(printf "%04d" $1)_out50.txt
  ot=`pwd`/$wdir/a50.out
  cat $ss | $ot 1> /dev/null 2> $oo
}
export -f tt

function tt2() {
  wdir=sh_work
  nn=$(printf "%04d" $1).txt
  ss=`pwd`/${wdir}/$nn
  echo $nn
  oo=`pwd`/${wdir}/$(printf "%04d" $1)_out100.txt
  ot=`pwd`/$wdir/a100.out
  cat $ss | $ot 1> /dev/null 2> $oo
}
export -f tt2

seq 0 $lim | xargs -P 5 -I {} bash -c "tt {}"
seq 0 $lim | xargs -P 5 -I {} bash -c "tt2 {}"
ex=0
sum=0
for ((i=0; i < $sz; i++)); do
  oo=`pwd`/${wdir}/$(printf "%04d" $i)_out50.txt
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
echo =====================
ex=0
sum=0
for ((i=0; i < $sz; i++)); do
  oo=`pwd`/${wdir}/$(printf "%04d" $i)_out100.txt
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