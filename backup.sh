#!/bin/bash

#1. Create back up file
mkdir -p backup

#Take realtime and put in display
FILE_TIME=$(date +"%Y%m%d_%H%M%S")
PRINT_TIME=$(date +"%H:%M:%S of %d/%m/%Y")

#2 & 3.Copy and change filename in backup (inventory.txt has to be in the same folder)
cp inventory.txt backup/inventory_${FILE_TIME}.txt

#4. Display success backup
echo "Successfully backed up at [${PRINT_TIME}]"
