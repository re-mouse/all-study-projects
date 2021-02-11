FROM debian:buster

RUN apt-get update
RUN apt-get install -y nginx
RUN apt-get install -y wget
RUN apt-get install -y curl
RUN apt-get install -y openssl vim
RUN apt-get install nginx mariadb-server mariadb-client php-cgi php-common php-fpm php-pear php-mbstring php-zip php-net-socket php-gd php-xml-util php-gettext php-mysql php-bcmath unzip wget git -y

RUN mkdir /root/scripts

WORKDIR /root/scripts/

RUN rm /etc/php/7.3/fpm/php.ini
COPY src/php.ini /etc/php/7.3/fpm/
RUN mkdir /var/www/wp
COPY src/wp /etc/nginx/sites-available/
RUN ln -s /etc/nginx/sites-available/wp /etc/nginx/sites-enabled/


WORKDIR /var/www/
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xzvf latest.tar.gz
RUN mv -f wordpress/* wp/
COPY src/wp-config.php ./wp/
RUN chown -Rv www-data:www-data /var/www/wp/
RUN mkdir /etc/nginx/templates/
COPY src/phpmyadmininstall.sh .
RUN bash phpmyadmininstall.sh
COPY src/phpmyadmin.conf /etc/nginx/templates/
COPY src/config.inc.php /usr/share/phpmyadmin

COPY src/mysqldb .
COPY src/mysql.sh .
RUN bash mysql.sh
RUN mkdir /etc/nginx/ssl/
RUN rm /etc/nginx/sites-enabled/default
COPY src/ssl.sh .
RUN bash ssl.sh
RUN mkdir /var/www/sites
RUN ln -s /var/www/wp /var/www/sites
RUN ln -s /usr/share/phpmyadmin /var/www/sites
RUN ln -s /var/www/html/index.nginx-debian.html /var/www/sites/PEARGIVEME100nginx.html

EXPOSE 80 443

COPY src/start.sh .

CMD ["/bin/bash", "start.sh"]