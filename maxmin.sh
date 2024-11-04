#!/bin/bash
echo "3개의 숫자를 입력해주세요."
read a
read b
read c

max=$a
min=$a
if [ $b -gt $max ]; then
	max=$b
fi

if [ $c -gt $max ]; then
	max=$c
fi

if [ $b -lt $min ]; then
	min=$b
fi

if [ $c -lt $min ]; then
	min=$c
fi

echo "가장 큰 수: $max"
echo "가장 작은 수 $min"
