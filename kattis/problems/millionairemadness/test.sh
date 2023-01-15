#!/bin/bash
for i in {1..3}
do
    echo "in progress $i"
    diff $i.out <(./millionairemadness < $i.in | tail -1)
    echo "done $i"
done

echo "DONE"
