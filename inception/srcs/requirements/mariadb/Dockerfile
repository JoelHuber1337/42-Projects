FROM alpine:3.23

ARG MARIADB_VERSION

RUN set -eux; \
	apk --no-cache add \
		mariadb=~${MARIADB_VERSION} \
		mariadb-client=~${MARIADB_VERSION}; \
        \
	mkdir -p /run/mysqld; \
	chown -R mysql:mysql /run/mysqld;

COPY --chmod=777 ./config/entry.sh /usr/local/bin/entrypoint
COPY --chmod=777 ./config/healthcheck.sh /usr/local/bin/mariadb_healthcheck.sh

ENTRYPOINT ["/usr/local/bin/entrypoint"]
CMD ["mariadbd"]