#!/bin/sh

# Check that PHP-FPM responds to a FastCGI ping
SCRIPT_NAME=/ping \
SCRIPT_FILENAME=/ping \
REQUEST_METHOD=GET \
cgi-fcgi -bind -connect "127.0.0.1:$WP_NGINX_PORT" 2>/dev/null \
    | grep -q '^pong' || exit 1

exit 0
