[AI USAGE]
Chatgpt helped me pick out dependencies for Wordpress

Versions used: (https://make.wordpress.org/hosting/handbook/compatibility/)
WP 7.0
Php 8.5
MariaDB 12.2 (until 2026-05)

https://developer.wordpress.org/advanced-administration/server/web-server/nginx/
"To make WordPress work with Nginx you have to configure the backend php-cgi. The options available are fastcgi or php-fpm. Here, php-fpm is being used because it is included with PHP 5.3+, so installing it is straight forward." => Only php-fpm or fastcgi for Wordpress Nginx needed

https://make.wordpress.org/hosting/handbook/server-environment/#php-extensions
