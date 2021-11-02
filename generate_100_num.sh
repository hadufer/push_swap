#!/bin/sh
ECHO=$(echo -n)
for i in {0..100}
do
	printf '%d ' $(echo "$RANDOM % 10000" | bc)
done
