#!/bin/bash
echo "Enter the number"
read v
n=$(($v))
sum=0
count=1
while [ $n -gt 0 ]
	do
		rem=$(( $n % 10 ))
		sum=$(((( $sum * 10 )) + $rem ))
		n=$(( $n / 10 ))
	done
if [ $v -eq $sum ]
	then
	echo "Palindrome"
else
	echo "Not Palindrome"
fi
