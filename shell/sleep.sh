#!/bin/bash

cout=0
while true;
do
echo "Hello World"
let "cout=${cout}+1"
if [ ${cout} == 20 ]
then
exit 0
fi
sleep 1
done
