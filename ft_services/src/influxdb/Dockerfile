FROM alpine:latest
RUN apk update
RUN apk add wget influxdb supervisor
COPY src/start.sh /
RUN mkdir -p /var/run/influxdb
RUN chmod +x /start.sh
RUN apk --no-cache add ca-certificates wget
RUN wget -q -O /etc/apk/keys/sgerrand.rsa.pub https://alpine-pkgs.sgerrand.com/sgerrand.rsa.pub
RUN wget https://github.com/sgerrand/alpine-pkg-glibc/releases/download/2.28-r0/glibc-2.28-r0.apk
RUN apk add glibc-2.28-r0.apk
RUN rm /etc/supervisord.conf
RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.17.0_linux_amd64.tar.gz
RUN tar xf telegraf-1.17.0_linux_amd64.tar.gz
RUN cp -R telegraf-1.17.0/* /
COPY src/telegraf.conf /etc/telegraf/telegraf.conf
VOLUME ["/var/lib/influxdb"]
COPY /src/supervisor.conf /etc/supervisord.conf
EXPOSE 8086
CMD ["/usr/bin/supervisord"]