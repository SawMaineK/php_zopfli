php_zopfli
==========
PHP-Extension for compressing content with zopfli. 

Install
==========
Put this single line in your php.ini and put the extension in the same place as the other default extensions
```
[win]
extension=php_zopfli.dll

[lin]
extension=php_zopfli.so
```

Example
==========
php_zopfli can be used as replacement for gzip compression. Just call zopfliencode() instead of gzencode().
The second argument is the iteration counter and can be some value between 1 and 1000. 
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
