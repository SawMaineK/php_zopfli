php_zopfli
==========

PHP-Extension for compressing content with zopfli. Can be used as replacement for gzip compression. 
Instead of calling gzencode() just call zopfliencode(). Seee usage example:

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
