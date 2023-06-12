#!/bin/sh
ifconfig | grep "ether" | sed "s/        //" | cut -d " " -f 2
