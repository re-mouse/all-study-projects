FROM alpine

RUN apk update
RUN apk add wget

RUN wget https://dl.grafana.com/oss/release/grafana-7.3.6.linux-amd64.tar.gz
RUN tar -zxvf grafana-7.3.6.linux-amd64.tar.gz
RUN apk add libgcc
COPY src/start.sh /
RUN chmod +x /start.sh
RUN apk --no-cache add ca-certificates wget
RUN wget -q -O /etc/apk/keys/sgerrand.rsa.pub https://alpine-pkgs.sgerrand.com/sgerrand.rsa.pub
RUN wget https://github.com/sgerrand/alpine-pkg-glibc/releases/download/2.28-r0/glibc-2.28-r0.apk
RUN apk add glibc-2.28-r0.apk
EXPOSE 3000
VOLUME ["/var/lib"]
COPY src/grafana.db /grafana-7.3.6/data/grafana.db
CMD ["/start.sh"]