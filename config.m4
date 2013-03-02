
PHP_ARG_ENABLE(zopfli, whether to enable zopfli support,
[ --enable-zopfli      Enable zopfli support])

if test "$PHP_ZOPFLI" != "no"; then
  PHP_NEW_EXTENSION(zopfli, zopfli.c, $ext_shared)
fi
