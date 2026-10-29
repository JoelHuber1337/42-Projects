#!/bin/sh

echo "NGINX Entry Script started..."

set -eu

echo "Checking the self signed certificate..."
if [ ! -f /etc/nginx/ssl/inception.crt ] || [ ! -f /etc/nginx/ssl/inception.key ]; then
    echo "Certificate missing, creating certificate..."
    openssl req \
		-x509 \
		-nodes \
		-days 365 \
		-newkey rsa:3072 \
		-keyout /etc/nginx/ssl/inception.key \
		-out /etc/nginx/ssl/inception.crt \
		-subj "/CN=$WP_DOMAIN" \
		-addext "subjectAltName=DNS:$WP_DOMAIN,DNS:*.$WP_DOMAIN" \
	> /dev/null 2>&1
    echo "Certificate has been created!"
else
    echo "Certificate exists!"
fi

echo "Overwriting nginx configs"

cat > /etc/nginx/conf.d/default.conf << EOF
server {
    server_name ${WP_DOMAIN};
    listen ${NGINX_PORT} ssl default_server;
    http2 on;

    # TLS
    ssl_protocols TLSv1.2 TLSv1.3;
    ssl_certificate /etc/nginx/ssl/inception.crt;
    ssl_certificate_key /etc/nginx/ssl/inception.key;
    ssl_prefer_server_ciphers on;
    ssl_ciphers ECDHE-ECDSA-AES128-GCM-SHA256:ECDHE-RSA-AES128-GCM-SHA256:ECDHE-ECDSA-AES256-GCM-SHA384:ECDHE-RSA-AES256-GCM-SHA384;
    ssl_session_timeout 1d;
    ssl_session_cache shared:SSL:10m;
    ssl_session_tickets off;

    # Security headers
    add_header X-Frame-Options "SAMEORIGIN" always;
    add_header X-Content-Type-Options "nosniff" always;
    add_header X-XSS-Protection "1; mode=block" always;

    root /var/www/html;
    index index.php index.html;

    location / {
        try_files $$uri $$uri/ /index.php?$$args;
    }

    location ~ \.php$$ {
        include fastcgi_params;
        fastcgi_pass wordpress:${WP_NGINX_PORT};
        fastcgi_param SCRIPT_FILENAME $$document_root$$fastcgi_script_name;
		fastcgi_param	HTTPS			$$https;
    }

    location ~* \.(js|css|png|jpg|jpeg|gif|ico|svg|woff|woff2)$$ {
        expires 30d;
        add_header Cache-Control "public, immutable";
    }

    # Deny access to hidden files
    location ~ /\. {
        deny all;
    }
}
EOF


echo "NGINX Entry Script finished!"

exec "$@"