FROM alpine

RUN apk update
RUN apk add supervisor openrc php-fpm wget nginx lighttpd php7-common php7-iconv php7-json php7-gd php7-curl php7-xml php7-mysqli php7-imap php7-cgi fcgi php7-pdo php7-pdo_mysql php7-soap php7-xmlrpc php7-posix php7-mcrypt php7-gettext php7-ldap php7-ctype php7-dom

COPY src/nginxconf.conf /etc/nginx/conf.d/default.conf

RUN wget http://wordpress.org/latest.tar.gz

RUN tar -xzvf latest.tar.gz

RUN adduser -D -g 'www' www

RUN mkdir /run/nginx
RUN mkdir /run/php

COPY src/wp-config.php /wordpress

RUN rm /etc/php7/php.ini

COPY src/php.ini /etc/php7/php.ini

COPY src/start.sh /
RUN chmod +x /start.sh

RUN rm /etc/supervisord.conf

COPY /src/supervisor.conf /etc/supervisord.conf

CMD ["/start.sh"]

EXPOSE 5050