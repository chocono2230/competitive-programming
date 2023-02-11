# 競プロ用各種コマンド

function ccp() {
    if [ $# != 2 ]; then
        echo 引数エラー: $# args
        return
    fi
    mkdir -p $1
    cd $1
    ff=${2}.cpp
    touch $ff in.txt
    code in.txt
    code $ff
}

function msenv() {
    export DEV_DY=$1
    export DEV_VC=$2
    echo DEV_DY is $DEV_DY
    echo DEV_VC is $DEV_VC
    echo "VC_1 忘れずに"
}

function clean() {
    rm */a.out
    rm */in.txt
}

function mkcd() {
    if [ -z $DEV_DY ]; then
        echo DEV_DY Error
        return
    fi
    if [[ $# != 2 && $# != 3 ]]; then
        echo 引数エラー: $# args
        echo \<contest\> \<problem\> \<number\(option\)\>
        return
    fi
    num="1"
    if [[ $# == 3 ]]; then
        num=$3
    fi
    f=${2}p_${DEV_DY}_${num}
    mkdir $f
    cd $f
    ff=${1}_${2}p_${DEV_DY}_${num}.cpp
    touch $ff in.txt
    code in.txt
    code $ff
}

function mkcdh() {
    if [ -z $DEV_DY ]; then
        echo DEV_DY Error
        return
    fi
    if [[ $# != 2 && $# != 3 ]]; then
        echo 引数エラー: $# args
        echo \<contest\> \<problem\> \<number\(option\)\>
        return
    fi
    num="1"
    if [[ $# == 3 ]]; then
        num=$3
    fi
    f=${2}h_${DEV_DY}_${num}
    mkdir $f
    cd $f
    ff=${1}_${2}h_${DEV_DY}_${num}.cpp
    touch $ff in.txt .gitignore
    code in.txt
    code $ff
}

alias c='code'
alias g='g++ -std=gnu++17 -Wall -Wextra -O2 -DCHOMONOLIS_LOCAL $1'
alias z='./a.out < in.txt'