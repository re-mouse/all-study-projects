apt install php-mbstring php-zip php-gd php-curl php-json php-gettext php-xml php-phpseclib
mkdir -p /var/lib/phpmyadmin/tmp
mkdir /usr/share/phpmyadmin
chown -R www-data:www-data /var/lib/phpmyadmin
cd
wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar xvf phpMyAdmin-5.0.2-all-languages.tar.gz -C /usr/share/phpmyadmin --strip-components 1
cd /usr/share/phpmyadmin
cp config.sample.inc.php config.inc.php
