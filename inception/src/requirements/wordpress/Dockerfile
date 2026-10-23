FROM alpine:3.23

# The TCP port PHP-FPM listens on.
# Keep this in sync with the listen setting in php-fpm.conf.
ENV WORDPRESS_FPM_PORT=9000

# fcgi: provides cgi-fcgi for the healthcheck.
# php85: PHP runtime and command-line interpreter.
# php85-fpm: runs PHP scripts through FastCGI.
# php85-phar: allows PHP Archive files, including WP-CLI, to run.
# php85-mysqli: connects WordPress to MariaDB/MySQL.
# php85-mbstring: handles multibyte text and Unicode strings.
# php85-xml: provides XML parsing functionality.
# php85-dom: provides the DOM API for XML and HTML.
# php85-simplexml: provides the SimpleXML API for XML data.
# php85-xmlreader: reads XML documents as a stream.
# php85-xmlwriter: writes XML documents as a stream.
# php85-curl: allows PHP code to make HTTP/HTTPS requests.
# php85-openssl: enables TLS and OpenSSL cryptographic functions.
# php85-gd: provides image processing and resizing.
# php85-exif: reads image metadata such as orientation.
# php85-fileinfo: detects file types and MIME types.
# php85-intl: provides internationalization and locale functions.
# php85-zip: handles ZIP archives used by themes and plugins.
# php85-sodium: provides modern cryptographic functions.
# php85-iconv: converts between character encodings.
# php85-tokenizer: tokenizes PHP source code.
# php85-session: provides PHP session handling.
# php85-ctype: provides character classification functions.
# ca-certificates: verifies TLS certificates for HTTPS downloads.
# su-exec: runs WP-CLI as the unprivileged wordpress user.
RUN set -eux; \
    apk add --no-cache \
        ca-certificates \
        fcgi \
        su-exec \
        php85 \
        php85-fpm \
        php85-phar \
        php85-mysqli \
        php85-mbstring \
        php85-xml \
        php85-dom \
        php85-simplexml \
        php85-xmlreader \
        php85-xmlwriter \
        php85-curl \
        php85-openssl \
        php85-gd \
        php85-exif \
        php85-fileinfo \
        php85-intl \
        php85-zip \
        php85-sodium \
        php85-iconv \
        php85-tokenizer \
        php85-session \
        php85-ctype

# Create a dedicated account for WordPress and PHP-FPM workers.
# Provide unversioned executable names for scripts and the CMD.
RUN set -eux; \
    addgroup -S -g 1000 wordpress; \
    adduser -S -D -H -u 1000 -G wordpress wordpress; \
    ln -sf /usr/bin/php85 /usr/bin/php; \
    ln -sf /usr/sbin/php-fpm85 /usr/sbin/php-fpm; \
    mkdir -p /var/www/html /tmp/wp-cli-home; \
    chown wordpress:wordpress /tmp/wp-cli-home

# Download WordPress and install WP-CLI.
# GPG and gpg-agent are temporary build dependencies.
# The signing-key fingerprint is pinned before the PHAR is accepted.
RUN set -eux; \
    apk add --no-cache --virtual .build \
        gpg \
        gpg-agent; \
    \
    GNUPGHOME="$(mktemp -d)"; \
    export GNUPGHOME; \
    chmod 700 "$GNUPGHOME"; \
    \
    wget -q -O /tmp/wordpress.tar.gz \
        https://wordpress.org/latest.tar.gz; \
    tar -xzf /tmp/wordpress.tar.gz \
        --strip-components=1 \
        -C /var/www/html; \
    \
    wget -q -O /tmp/wp-cli.phar \
        https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar; \
    wget -q -O /tmp/wp-cli.phar.asc \
        https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar.asc; \
    wget -q -O /tmp/wp-cli.pgp \
        https://raw.githubusercontent.com/wp-cli/builds/gh-pages/wp-cli.pgp; \
    \
    gpg --batch --import /tmp/wp-cli.pgp; \
    fingerprint="$(gpg --batch --with-colons --fingerprint releases@wp-cli.org \
        | awk -F: '$1 == "fpr" { print $10; exit }')"; \
    test "$fingerprint" = "63AF7AA15067C05616FDDD88A3A2E8F226F0BC06"; \
    gpg --batch --verify /tmp/wp-cli.phar.asc /tmp/wp-cli.phar; \
    \
    install -m 755 /tmp/wp-cli.phar /usr/local/bin/wp; \
    php /usr/local/bin/wp --info > /dev/null; \
    \
    gpgconf --kill all || true; \
    rm -rf "$GNUPGHOME" \
        /tmp/wordpress.tar.gz \
        /tmp/wp-cli.phar \
        /tmp/wp-cli.phar.asc \
        /tmp/wp-cli.pgp; \
    apk del .build

# Install your own PHP and WP-CLI configuration.
COPY ./config/php.ini /etc/php85/conf.d/99_inception.ini
COPY ./config/php-fpm.conf /etc/php85/php-fpm.d/www.conf
COPY --chown=wordpress:wordpress ./config/wp-cli.yml /var/www/html/wp-cli.yml
COPY --chmod=755 ./config/entry.sh /usr/local/bin/entrypoint

# Allow the wordpress account to read and manage its WordPress files.
# This also allows the entrypoint to create wp-config.php as that user.
RUN set -eux; \
    chown -R wordpress:wordpress /var/www/html; \
    php-fpm -t

WORKDIR /var/www/html

# Document the FastCGI port used by the Nginx container.
EXPOSE 9000

# Check the FastCGI ping endpoint, not an ordinary PHP page.
# The endpoint must be enabled in the PHP-FPM pool configuration.
HEALTHCHECK --start-period=30s --interval=30s --timeout=5s --retries=3 \
    CMD SCRIPT_NAME=/ping SCRIPT_FILENAME=/ping REQUEST_METHOD=GET \
        cgi-fcgi -bind -connect "127.0.0.1:${WORDPRESS_FPM_PORT}" \
        | grep -q pong

# Let the entrypoint initialize WordPress before starting PHP-FPM.
ENTRYPOINT ["/usr/local/bin/entrypoint"]
CMD ["php-fpm", "-F"]

