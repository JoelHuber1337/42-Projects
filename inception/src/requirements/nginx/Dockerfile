FROM alpine:3.23

RUN set -eux; \
    apk --no-cache add \
        nginx \
        openssl \
        ca-certificates \
    mkdir -p /etc/nginx/ssl;

COPY --chmod=777 config/entry.sh /usr/local/bin/entrypoint

ENTRYPOINT [/usr/local/bin/entrypoint]
CMD ["nginx", "-g", "daemon off;"]