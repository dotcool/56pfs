#!/bin/sh

ulimit -c 1024000
killall pfs_master -9

sleep 2;

dir=`dirname $0`
cd $dir
./pfs_master
