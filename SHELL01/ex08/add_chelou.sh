#!/bin/sh
echo $FT_NBR1 $FT_NBR2 | tr "'" "0" | sed 's@\\@1@g'| tr "\"" "2" | tr "?" "3" | tr "\!" "4" | tr "mrdoc" "01234" | tr " " ";" | xargs echo "ibase=5;" | bc | tr "\n" "|" | sed "s/|$/./" | tr "." "\n" | sed "s/|/ + /" | bc | xargs echo "obase=13;" | bc | tr "0123456789ABC" "gtaio luSnemf"
