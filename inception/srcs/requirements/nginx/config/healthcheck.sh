#!/bin/sh

wget -q \
    --no-check-certificate \
    --tries=1 \
    --timeout=3 \
    -O /dev/null \
    "https://127.0.0.1:${NGINX_PORT}/readme.html"