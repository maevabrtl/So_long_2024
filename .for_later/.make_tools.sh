!bin/bash

find ./ -name "so_long" > .find
echo ".//so_long" > .check_comp
echo $? > .find
rm .check_comp
