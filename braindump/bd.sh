#! /bin/sh
if [ $# -ne 0 ]
  then
    echo "$(date): $@" | tee -a bd.txt
fi
