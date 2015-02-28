dnl $Id: $
dnl config.m4 for extension zopfli

PHP_ARG_ENABLE(zopfli, whether to enable zopfli support,
[ --enable-zopfli      Enable zopfli support])

if test "$PHP_ZOPFLI" != "no"; then

  zopfli_sources="zopfli/zopfli_bin.c\
					php_zopfli.c"

  PHP_NEW_EXTENSION(zopfli, php_zopfli.c, $ext_shared)
  PHP_ADD_BUILD_DIR([$ext_builddir/zopfli])
fi
