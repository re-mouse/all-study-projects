FROM alpine

RUN apk update
RUN apk add supervisor openrc php-fpm wget nginx lighttpd php7-common php7-iconv php7-json php7-gd php7-curl php7-xml php7-mysqli php7-imap php7-cgi fcgi php7-pdo php7-pdo_mysql php7-soap php7-xmlrpc php7-posix php7-mcrypt php7-gettext php7-ldap php7-ctype php7-dom php7-mbstring php-cgi php-common php-fpm php-pear php-mbstring php-zip php-gd php-gettext php-bcmath php7-session

RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz

RUN mkdir /var/www/localhost/htdocs/phpmyadmin

RUN tar -xzvf phpMyAdmin-5.0.2-all-languages.tar.gz -C /var/www/localhost/htdocs/phpmyadmin --strip-components 1

RUN adduser -D -g 'www' www

RUN mkdir /run/nginx
RUN mkdir /run/php

RUN mkdir -p /var/lib/phpmyadmin/tmp

RUN chown -R www:www /var/lib/phpmyadmin

RUN cp /var/www/localhost/htdocs/phpmyadmin/config.sample.inc.php /var/www/localhost/htdocs/phpmyadmin/config.inc.php

COPY src/config.inc.php /var/www/localhost/htdocs/phpmyadmin/

RUN rm /etc/php7/php.ini

COPY src/php.ini /etc/php7/php.ini

COPY src/start.sh /
RUN chmod +x /start.sh

RUN rm /etc/supervisord.conf

COPY /src/supervisor.conf /etc/supervisord.conf
COPY src/nginxconf.conf /etc/nginx/conf.d/default.conf

CMD ["/start.sh"]

EXPOSE 5000