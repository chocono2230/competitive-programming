#!/bin/bash
set -e

if [ $# != 3 ]; then
    echo 引数エラー: $# args
    echo \<test_case_size\> \<code\> \<create_testcase\[True or any\]\>
    exit 1
fi
readonly SZ=$1
readonly SOURECE_CODE=$2
readonly CREATE_TESTCASE=$3
readonly LIM=$((SZ-1))
readonly W_DIR=sh_work
export readonly NOW_DIR=`pwd`/$W_DIR
readonly ARTIFACTS_DIR=`pwd`/sh_artifacts
export readonly INPUT_DIR=`pwd`/sh_input
readonly RESULT_FILE=$ARTIFACTS_DIR/result.txt

rm -rf $W_DIR
mkdir $W_DIR

if [ -e $RESULT_FILE ]; then
  rm $RESULT_FILE
fi
touch $RESULT_FILE

if [ $CREATE_TESTCASE = "True" ]; then
  rm -rf $INPUT_DIR
  z=`pwd`/script/make_random.cpp
  g++ -std=gnu++17  -Wall -Wextra -O2 $z -o ${NOW_DIR}/a.out
  ot=${NOW_DIR}/a.out
  p=$RANDOM
  $ot $p $SZ > ./$W_DIR/seed.txt

  cd ./tools
  rm -rf ./in
  cargo run --release --bin gen ../$W_DIR/seed.txt
  cp -r ./in $INPUT_DIR
  cd ..
fi

z=`pwd`/$SOURECE_CODE
g++ -std=gnu++17 -Wall -Wextra -O2 -DCHOCONO_LOCAL $z -o ${NOW_DIR}/a.out
export readonly MAIN_PROGRAM=${NOW_DIR}/a.out

function tt() {
  nn=$(printf "%04d" $1).txt
  ss=${INPUT_DIR}/$nn
  echo $nn
  oo=${NOW_DIR}/$(printf "%04d" $1)_out.txt
  cat $ss | $MAIN_PROGRAM 1> /dev/null 2> $oo
}
export -f tt

seq 0 $LIM | xargs -P 5 -I {} bash -c "tt {}"
for ((i=0; i < $SZ; i++)); do
  FILE_NAME=${NOW_DIR}/$(printf "%04d" $i)_out.txt
  rpco=case:$i
  while read line
  do
    if [[ "$line" =~ "artifacts:"* ]]; then
      rpco=$rpco,${line#*artifacts:}
    fi
  done < ${FILE_NAME}
  echo $rpco >> $RESULT_FILE
done
python3 ./script/calc_score.py