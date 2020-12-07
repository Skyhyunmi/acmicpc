#! /bin/zsh

g++ $1.cpp -std=c++14
if [ $# = 1 ]; then
    ./a.out

else
    ./a.out < $2 > $2.myans
    # cat $2.myans
    if [ -z "$(diff -c $2.myans $2.ans)"]; then
        cat $2.myans
        echo "answer is correct"
    else echo "answer is wrong"
    fi
fi