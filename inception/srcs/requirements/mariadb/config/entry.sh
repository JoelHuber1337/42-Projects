#!/bin/sh

echo "Mariadb Entry Script called..."

set -eu

cat > /etc/my.cnf << EOF
[client-server]
port = ${MARIADB_PORT}
socket = /run/mysqld/mysql.sock

[client]
password = ${DB_PWD}

[server]
user = mysql
datadir = /var/lib/mysql
bind-address = 0.0.0.0
local-infile = 0
EOF

echo "Checking if the database exists..."

if [ ! -d "/var/lib/mysql/mysql" ]; then
	echo "Database doesn't exist, creating Database..."
	mariadb-install-db --skip-test-db
else
	echo "Database already exists!"
fi

echo "Checking if Mariadb is set up with WP"
if [ ! -d "/var/lib/mysql/${DB_NAME}" ]; then
	echo "WP is not set up in MariaDB, setting up..."
	cat > /tmp/tmp.conf << EOF
FLUSH PRIVILEGES;

ALTER USER \`root\`@\`localhost\` IDENTIFIED BY '${DB_ROOT_PWD}';

CREATE DATABASE IF NOT EXISTS \`${DB_NAME}\`;

CREATE USER IF NOT EXISTS \`${DB_USER}\`@\`%\` IDENTIFIED BY '${DB_PWD}';

GRANT ALL PRIVILEGES ON \`${DB_NAME}\`.* TO \`${DB_USER}\`@\`%\`;

FLUSH PRIVILEGES;
EOF
	mariadbd --bootstrap < /tmp/tmp.conf
	rm -r /tmp/tmp.conf
	echo "Mariadb set up and bootstrapped"
else
	echo "Mariadb is set up with wordpress!"
fi

exec "$@"