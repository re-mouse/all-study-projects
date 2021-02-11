openssl req -x509 -sha256 -nodes -days 365 -newkey rsa:4096 -keyout /etc/nginx/ssl/certp.key -out /etc/nginx/ssl/certp.crt \
	-subj '/C=RU/ST=KAZAN/L=KAZAN/O=SCHOOL 21!/OU=21/emailAddress=root@primer.com/CN=primer.com'

cd /usr/share/phpmyadmin
service mysql start
mysql -u root < sql/create_tables.sql