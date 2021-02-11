#!/bin/sh
rc default
/etc/init.d/mariadb setup
cat >> /etc/my.cnf << EOF
bind-address    = 0.0.0.0
skip-networking = false
EOF
/etc/init.d/mariadb start
mysql < mysqlexport
/etc/init.d/mariadb stop
/usr/bin/mysqld_safe