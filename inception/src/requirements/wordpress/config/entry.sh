#!/bin/sh

echo "WP Entry Script called..."

echo "Checking if WP is installed"
if ! wp core version  --allow-root > /dev/null 2>&1; then
    echo "WP is not installed, installing WP version $(WP_VERSION)"
    wp core download --version="$WP_VERSION" --allow-root
else
    echo "WP is installed"
fi

echo "Checking WP config..."
if ! wp config path --allow-root > /dev/null 2>&1; then
    echo "No config set, setting config"
    wp config create \
        --dbname="$DB_NAME" \
        --dbuser="$DB_USER" \
        --dbpass="$DB_PWD" \
        --dbhost="$DB_HOST" \
        --allow-root
else
    echo "WP Config exists."
fi

echo "Waiting for mariadb..."

attempt=1
while ! wp db check --allow-root > /dev/null 2>&1; do
    if ["$attempt" -ge 60 ]; then
        echo "WP couldn't connect to mariadb after 60 tries"
        exit 1
    fi

    echo "WP connection to mariadb failed, retrying..."
    attempt=$((attempt + 1))
    sleep 1
done

echo "WP successfully connected to mariadb"

echo "Checking WP Website Configs..."
if ! wp core is-installed --path="$WP_DIR" --allow-root 2>/dev/null; then
    echo "Setting up WP..."
    echo "Creating Admin User..."
    wp core install \
        --url="$WP_URL:$NGINX_PORT" \
        --title="$WP_TITLE" \
        --admin_user="$WP_ADMIN" \
        --admin_password="$WP_ADMIN_PWD" \
        --admin_email="$WP_ADMIN_EMAIL" \
        --skip-email \
        --allow-root

    echo "Creating WP User..."
    wp user create \
        "${WP_USER}" \
        "${WP_USER_EMAIL}" \
        --role=author \
        --user_pass="$WP_USER_PWD" \
        --path="$WP_DIR" \
        --allow-root
    echo "WP successfully set up!"
else
    echo "WP is already set up"
fi


echo "WP Entry Script finished!"
exec $@