#!/bin/bash

array_var={1,2,3,4,5,6}
array_var[1]="song"
array_var[2]="shuang"
array_var[3]="Hang"
array_var[4]="Zhou"
array_var[5]="ZheJiang"
ayyay_var[6]="NEC"

echo ${array_var[*]}

echo ${#array_var[*]}
