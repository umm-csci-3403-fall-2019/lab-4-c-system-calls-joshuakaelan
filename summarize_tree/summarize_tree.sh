#!/usr/bin/env bash

dir=$1

countd=$(find $dir -type d | wc -l)
echo "There were" $countd "directories." 

countf=$(find $dir -type f | wc -l)
echo "There were" $countf "regular files." 


