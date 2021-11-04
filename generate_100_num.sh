#!/bin/sh
TMP=0
for i in {0..99}
do
	TMP=$(expr $(./push_swap `ruby -e "puts (0..500).to_a.shuffle.join(' ')"` | wc -w | bc) + $TMP)
done
TMP=$(expr $TMP / 100)
echo $TMP
