FROM alpine

RUN apk update
RUN apk add nginx openssl openssh supervisor

RUN adduser -D -g 'www' www

RUN adduser -D ssh

RUN echo 1234qwer > pswr
RUN echo 1234qwer >> pswr
RUN passwd ssh < pswr

RUN mkdir /etc/nginx/ssl/
RUN mkdir /run/nginx
RUN openssl req -x509 -sha256 -nodes -days 365 -newkey rsa:4096 -keyout /etc/nginx/ssl/certp.key -out /etc/nginx/ssl/certp.crt -subj '/C=RU/ST=KAZAN/L=KAZAN/O=SCHOOL 21!/OU=21/emailAddress=root@primer.com/CN=primer.com'

COPY src/start.sh ./tmp
RUN chmod +x /tmp/start.sh

EXPOSE 80 443 22

COPY /src/supervisor.conf /etc/supervisord.conf
COPY src/nginxconf.conf /etc/nginx/conf.d/default.conf

CMD ["/tmp/start.sh"]