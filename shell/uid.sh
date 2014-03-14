#!/usr/bash
if [[ $UID -ne 0 ]]; then
	echo Non Root user. Please run root user
else
	echo Root user
fi