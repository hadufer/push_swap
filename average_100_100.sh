#!/bin/sh
TMP=0
for i in {0..99}
do
	TMP=$(expr $(export ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"` && ./push_swap $ARG | wc -l | bc) + $TMP)
done
TMP=$(expr $TMP / 100)
echo $TMP


