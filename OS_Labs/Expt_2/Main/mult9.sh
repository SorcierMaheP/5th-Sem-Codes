#!/bin/bash
echo "Enter the number of multiples of 9"
read mults
mult=9
for((i=1;i<=$mults;i++))
	do
		a=$(( $i * $mult ))
		printf "%d\n" "$a"
	done 
