FROM alpine

RUN apk update
RUN adduser -D -g 'www' www
RUN apk add mariadb mariadb-client openrc
RUN openrc
RUN touch /run/openrc/softlevel
COPY src/mysqlexport .
RUN chmod a+xwr ./mysqlexport
COPY src/start.sh .
VOLUME [ “/sys/fs/cgroup” ]
RUN chmod a+xwr ./start.sh
EXPOSE 3306
CMD ["/start.sh"]