#!/bin/bash
echo "Enter the number"
read num
if [ $(expr $num % 2) -eq 0 ]
	then 
		echo -n "Even number"
else
		echo -n "Odd number"
fi
