#!/bin/bash
set -e

if [ $# != 2 ]; then
    echo 引数エラー: $# args
    echo \<test_case_size\> \<code\>
    exit 1
fi
readonly SZ=$1
readonly SOURECE_CODE=$2
readonly LIM=$((SZ-1))
readonly W_DIR=sh_work
export readonly NOW_DIR=`pwd`/$W_DIR
readonly ARTIFACTS_DIR=`pwd`/sh_artifacts
export readonly INPUT_DIR=`pwd`/sh_input
export readonly SO_DIR=~/tools/ahc-so-dir
readonly RESULT_FILE=$ARTIFACTS_DIR/result.txt
readonly TIME_FILE=$ARTIFACTS_DIR/time.txt

rm -rf $W_DIR
mkdir $W_DIR
rm -rf $SO_DIR
mkdir $SO_DIR

if [ -e $RESULT_FILE ]; then
  rm $RESULT_FILE
fi
touch $RESULT_FILE

if [ -e $TIME_FILE ]; then
  rm $TIME_FILE
fi
touch $TIME_FILE

rm -rf $INPUT_DIR

if [ -e ./$W_DIR/seed.txt ]; then
  rm ./$W_DIR/seed.txt
fi

for ((i=0; i < $SZ; i++)); do
  echo $i >> ./$W_DIR/seed.txt
done

cd ./tools
cargo run --release --bin gen ../$W_DIR/seed.txt --dir=$INPUT_DIR
cd ..

z=`pwd`/$SOURECE_CODE
g++ -std=gnu++17 -Wall -Wextra -O2 -DCHOCONO_LOCAL $z -o ${NOW_DIR}/a.out
export readonly MAIN_PROGRAM=${NOW_DIR}/a.out

function tt() {
  nn=$(printf "%04d" $1).txt
  ss=${INPUT_DIR}/$nn
  echo $nn
  oo=${NOW_DIR}/$(printf "%04d" $1)_out.txt
  so=${SO_DIR}/${1}_so.txt
  cat $ss | $MAIN_PROGRAM 1> $so 2> $oo
  cp $oo ${SO_DIR}/${1}_out.txt
}
export -f tt

seq 0 $LIM | xargs -P 5 -I {} bash -c "tt {}"
for ((i=0; i < $SZ; i++)); do
  FILE_NAME=${NOW_DIR}/$(printf "%04d" $i)_out.txt
  rpco=case:$i
  times=case:$i
  while read line
  do
    if [[ "$line" =~ "artifacts:"* ]]; then
      rpco=$rpco,${line#*artifacts:}
    fi
    if [[ "$line" =~ "time:"* ]]; then
      times=$times,${line#*time:}
    fi
  done < ${FILE_NAME}
  echo $rpco >> $RESULT_FILE
  echo $times >> $TIME_FILE
done
python3 ./script/calc_score.py