FROM alpine:3.23

ARG WP_CLI_FP
ARG WP_DIR

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
        php85-ctype \
        php85-pecl-igbinary \
        php85-pecl-imagick  \
        php85-intl \
        ;

# Download WordPress and install WP-CLI.
# GPG and gpg-agent are temporary build dependencies.
# The signing-key fingerprint is pinned before the PHAR is accepted.
RUN set -eux; \
    apk add --no-cache --virtual .build \
        gpg \
        gpg-agent \
        wget; \
    \
    GNUPGHOME="$(mktemp -d)"; \
    export GNUPGHOME; \
    chmod 700 "$GNUPGHOME"; \
    wget -q -O /tmp/wp-cli.phar \
        https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar; \
    wget -q -O /tmp/wp-cli.phar.asc \
        https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar.asc; \
    wget -q -O /tmp/wp-cli.pgp \
        https://raw.githubusercontent.com/wp-cli/builds/gh-pages/wp-cli.pgp; \
    \
    gpg --batch --import /tmp/wp-cli.pgp; \
    gpg --batch --with-colons --list-keys --with-fingerprint \
    | awk -F: -v expected="${WP_CLI_FP}" ' \
        $1 == "pub" { primary = 1; next } \
        $1 == "sub" { primary = 0; next } \
        $1 == "fpr" && primary && \
        $10 == expected { \
            found = 1 \
        } \
        END { exit !found }'; \
    gpg --batch --verify /tmp/wp-cli.phar.asc /tmp/wp-cli.phar; \
    \
    install -m 777 /tmp/wp-cli.phar /usr/local/bin/wp; \
    php85 /usr/local/bin/wp --info > /dev/null; \
    \
    gpgconf --kill all || true; \
    rm -rf "$GNUPGHOME" \
        /tmp/wp-cli.phar \
        /tmp/wp-cli.phar.asc \
        /tmp/wp-cli.pgp; \
    apk del .build

# Install your own PHP and WP-CLI configuration.
COPY ./config/php-fpm.conf /etc/php85/php-fpm.d/www.conf
COPY ./config/php.ini /etc/php85/conf.d/php_conf.ini
COPY --chmod=777 ./config/entry.sh /usr/local/bin/entrypoint
COPY --chmod=777 ./config/healthcheck.sh /usr/local/bin/wp_healthcheck.sh

#working directory for the finished WP installation
RUN mkdir -p ${WP_DIR}; \
    ln -s /usr/bin/php85 /usr/bin/php; \
    ln -s /usr/sbin/php-fpm85 /usr/sbin/php-fpm; \
    adduser -u 1000 -H -D -S wordpress;

# Document the FastCGI port used by the Nginx container.
EXPOSE ${WP_NGINX_PORT}

WORKDIR ${WP_DIR}

# Let the entrypoint initialize WordPress before starting PHP-FPM.
ENTRYPOINT ["/usr/local/bin/entrypoint"]
CMD ["php-fpm", "-F", "--allow-to-run-as-root"]