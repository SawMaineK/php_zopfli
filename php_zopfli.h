/****************************************************************************
 *
 *  Copyright (c) 2013 clickalicious UG
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 ***************************************************************************/

#ifndef PHP_ZOPFLI_H
#define PHP_ZOPFLI_H 1

extern zend_module_entry zopfli_module_entry;
#define phpext_zopfli_ptr &zopfli_module_entry

#define PHP_ZOPFLI_VERSION "0.2"
#define PHP_ZOPFLI_EXTNAME "zopfli"

#ifdef PHP_WIN32
#define PHP_ZOPFLI_API __declspec(dllexport)
#else
#define PHP_ZOPFLI_API
#endif

// get zopfli files and headers
#include "zopfli/util.c"
#include "zopfli/tree.c"
#include "zopfli/deflate.c"
#include "zopfli/gzip_container.c"
#include "zopfli/katajainen.c"
#include "zopfli/lz77.c"
#include "zopfli/cache.c"
#include "zopfli/squeeze.c"
#include "zopfli/blocksplitter.c"
#include "zopfli/hash.c"

#ifdef ZTS
#include "TSRM.h"
#endif

/**
 * PHP default module methods
 */
PHP_MINIT_FUNCTION(zopfli);
PHP_MSHUTDOWN_FUNCTION(zopfli);

/**
 * declare methods available in PHP
 */
PHP_FUNCTION(zopfliencode);

#endif  /* PHP_ZOPFLI_H */
