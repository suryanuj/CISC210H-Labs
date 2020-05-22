#!/bin/bash

while [ -z "$IP" ]
do
	IP=$(ifconfig wlan0 | sed -n 's/.*inet \([0-9.]\+\)\s.*/\1/p')
	sleep 1
done
~/bin/scrollnum $IP
