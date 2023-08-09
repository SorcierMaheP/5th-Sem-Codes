#!/bin/bash
echo "Enter the number"
read n
count=2
while [ $count -lt $n ]
do
	d=$(( $n % $count ))
	if [ $d -eq 0 ]
	then 
		echo "Not prime number"
		exit
	fi
count=$(( $count + 1 ))
done
echo "Prime number"
