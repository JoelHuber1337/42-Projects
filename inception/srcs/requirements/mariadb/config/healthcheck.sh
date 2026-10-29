#!/bin/sh

# Test the database connection
mariadb \
    --protocol=tcp \
    --host=127.0.0.1 \
    --port="$MARIADB_PORT" \
    --connect-timeout=2 \
    --user="$DB_USER" \
    --password="$DB_PWD" \
    --database="$DB_NAME" \
    --execute="SELECT 1" \
    > /dev/null 2>&1
