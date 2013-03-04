
php_zopfli
==========
PHP-Extension for compressing content with zopfli. 


Install
==========
Put this single line in your php.ini and put the extension in the same place as the other default extensions
```
extension=php_zopfli.(so|dll)
```


Configure defaults
==========
Optional configure the default number of iterations in your php.ini. Whenever you call zopfliencode() without the 2nd argument the php.ini default value is used instead.
```
[Zopfli]
zopfli.iterations = 5
```


Example
==========
php_zopfli can be used as replacement for gzip/zlib compression - zopfli is 100% compatible with gzip + zlib so your browser will understand the zopfli output as well - just call zopfliencode() instead of gzencode(). The second argument is the optional iteration counter (a value between 1 and [max?]1000).
Usage example:

```php
<?php

$buffer = 'put some longer story here ...';

/*
 * call zopfliencode instead of gzencode()
 * @param string  The string to encode/compress
 * @param integer Number of iterations for compression (1 - 1000 [default = 5])
 */
$data = zopfliencode($buffer, 1);

header('Content-Encoding: gzip');
header('Content-Length: '.strlen($data));
header('Cache-Control: no-cache, no-store, max-age=0, must-revalidate');
header('Pragma: no-cache');

// output data
echo $data;

?>
```


More Information
==========
Zopfli was written by Jyrki Alakuijala, Ph.D. and Lode Vandevenne, M.Sc. from Google Inc.
You will find the projects homepage here: http://code.google.com/p/zopfli/
and the whitepaper here: http://code.google.com/p/zopfli/downloads/detail?name=Data_compression_using_Zopfli.pdf.
