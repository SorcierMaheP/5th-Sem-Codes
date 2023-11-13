#!/bin/bash
echo "Enter the number"
read num
sec_small=10
small=10
sec_large=-1
large=-1
for((i=0;i<${#num};i++))
	do
			if [ ${num:i:1} -gt $large ]; then
				sec_large=$large
				large=${num:i:1}
			fi
			if [ ${num:i:1} -lt $large ] && [ ${num:i:1} -gt $sec_large ]; then
				sec_large=${num:i:1}
			fi
			if [ ${num:i:1} -lt $small ]; then
				sec_small=$small
				small=${num:i:1}
			fi
			if [ ${num:i:1} -gt $small ] && [ ${num:i:1} -lt $sec_small ]; then
				sec_small=${num:i:1}
			fi
	done
if [ $sec_large -eq -1 ] || [ $sec_small -eq 10 ]; then
	echo "No second largest or second smallest digits available."
else
	echo -e "Second smallest:$sec_small\nSecond largest:$sec_large"
fi
	
