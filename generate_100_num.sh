#!/bin/sh
ECHO=$(echo -n)
# for i in {0..99}
# do
# 	printf '\"%d\", ' $(echo "$RANDOM % 10000"| bc)
# done

for i in {0..499}
do
	printf '%d ' $(echo "$RANDOM % 10000"| bc)
done
