FROM alpine:3.23

RUN set -eux; \
    apk --no-cache add \
        nginx \
        openssl \
        ca-certificates; \
    mkdir -p /etc/nginx/ssl /etc/nginx/conf.d/

COPY --chmod=777 config/entry.sh /usr/local/bin/entrypoint
COPY --chmod=777 config/healthcheck.sh /usr/local/bin/nginx_healthcheck.sh

EXPOSE ${NGINX_PORT}

ENTRYPOINT ["/usr/local/bin/entrypoint"]
CMD ["nginx", "-g", "daemon off;"]