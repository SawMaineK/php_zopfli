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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef linux
/* To enable CPU_ZERO and CPU_SET, etc. */
# define _GNU_SOURCE
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_zopfli.h"
#include "Zend/zend_extensions.h"

// get zopfli required lib files
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deflate.h"
#include "gzip_container.h"


/* compiled function list so Zend knows what's in this module */    
zend_function_entry zopfli_functions[] = {    
   ZEND_FE(zopfliencode, NULL)
   {NULL, NULL, NULL}
};

/* compiled module information */    
zend_module_entry zopfli_module_entry = {  
  #if ZEND_MODULE_API_NO >= 20010901  
    STANDARD_MODULE_HEADER,           // Roughly means if PHP Version > 4.2.0  
  #endif  
    PHP_ZOPFLI_EXTNAME,               // Define PHP extension name  
    zopfli_functions,                 /* Functions */  
    NULL,                             /* MINIT */  
    NULL,                             /* MSHUTDOWN */  
    NULL,                             /* RINIT */  
    NULL,                             /* RSHUTDOWN */  
    NULL,                             /* MINFO */  
  #if ZEND_MODULE_API_NO >= 20010901  
    PHP_ZOPFLI_VERSION,               // Roughly means if PHP Version > 4.2.0  
  #endif  
    STANDARD_MODULE_PROPERTIES  
};  
#ifdef COMPILE_DL_ZOPFLI
ZEND_GET_MODULE(zopfli)     // Common for all PHP extensions which are build as shared modules
#endif


ZEND_FUNCTION(zopfliencode);


/* ZOPFLI */
ZEND_FUNCTION(zopfliencode)
{
    char    *buffer;
    size_t   len_buffer;
    char    *output      = 0;
    size_t   len_output  = 0;
    int      iterations  = 1;
    Options  options;
    char    *result;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|s", &buffer, &iterations) == FAILURE) {
        //RETURN_STRING("Bad parameters!", 1);
        RETURN_NULL();
    }

    // size of input buffer
    len_buffer = strlen(buffer);

    // set options defaults
    options.verbose            = 0;
    options.numiterations      = iterations;
    options.blocksplitting     = 1;
    options.blocksplittinglast = 0;
    options.blocksplittingmax  = 15;

    // compress input
    GzipCompress(&options, buffer, len_buffer, &output, &len_output);
    
    // return result STRINGL ->
    // cause otherwise binary data could be cutted randomly at \0 null byte in string
    RETURN_STRINGL(output, len_output, 1);
}
