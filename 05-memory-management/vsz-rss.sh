#!/bin/bash

# プロセス毎のメモリ統計情報を表示
# vsz: 仮想メモリの量
# rss: 確保済みの物理メモリ料
# maj_flt: プロセス生成時からのページフォールト総数
# min_flt: プロセス生成時からのページフォールト総数

while true ; do
    DATE=$(date | tr -d '\n')
    INFO=$(ps -eo pid,comm,vsz,rss,maj_flt,min_flt | grep .out | grep -v grep)
    if [ -z "$INFO" ] ; then
        echo "$DATE: target process seems to be finished"
        break
    fi
    echo "${DATE}: ${INFO}"
    sleep 1
done