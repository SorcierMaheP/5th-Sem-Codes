#!/bin/bash
for((i=10;i<=60;i++))
	do
	if !(($i%4)); then
		echo " $i "
	fi
	done
