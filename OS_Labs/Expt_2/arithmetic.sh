#!/bin/bash
echo "Enter the values of a and b"
read a b
echo -e "1]Addition.\n2]Subtraction.\n3]Multiplication.\n4]Division.\n5]Modulo.\n6]Power.\n"

read choice

case $choice in
	1)
		ans=$(($a + $b))
		echo "Sum = $ans"
		;;
	2)
		ans=$(($a - $b))
		echo "Difference = $ans"
		;;
	3)
		ans=$(($a * $b))
		echo "Product = $ans"
		;;
	4)
		ans1=$(($a / $b))
		ans2=$(($a - $b * $ans1))
		echo "Quotient = $ans1"
		echo "Remainder = $ans2"
		;;
	5)
		ans=$(($a % $b))
		echo "Modulo = $ans"
		;;
	6)
		ans=$(($a ** $b))
		echo "Power = $ans"
		;;
	*)	echo "Wrong number entered"
esac
