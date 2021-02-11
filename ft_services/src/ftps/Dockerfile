FROM alpine

RUN apk update
RUN apk add vsftpd openssl supervisor

RUN echo "root:root" | chpasswd

RUN openssl req -x509 -sha256 -nodes -days 365 -newkey rsa:4096 -keyout /cert.pem -out /cert.pem -subj '/C=RU/ST=KAZAN/L=KAZAN/O=SCHOOL 21!/OU=21/emailAddress=root@primer.com/CN=primer.com'

COPY src/start.sh ./tmp
RUN chmod +x /tmp/start.sh

EXPOSE 21 30021

COPY src/vsftpd.conf /etc/vsftpd.conf

COPY src/supervisor.conf /etc/supervisord.conf

CMD ["/tmp/start.sh"]