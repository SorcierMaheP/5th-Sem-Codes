#!/bin/bash
echo -e "Enter 1 for circle.\nEnter 2 for triangle.\nEnter 3 for rectangle.\n"
read choice
case $choice in
	1)
		echo "Enter radius of circle"
		read r
		PI=3
		ans=$(($PI*$r*$r))
		echo "$ans"
		;;
	2)
		echo "Enter base and height of triangle"
		read b h
		ans=$(($b*$h/2))
		echo "$ans"
		;;
	3)	
		echo "Enter sides of rectangle"
		read b l
		ans=$(($b*$l))
		echo "$ans"
		;;
	*)
		echo "Wrong number entered"
esac
