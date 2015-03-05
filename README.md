<img src="https://avatars2.githubusercontent.com/u/514566?v=3&u=4615dfc4970d93dea5d3eaf996b7903ee6e24e20&s=140" align="right" />
---
# php_zopfli

![Logo of php_zopfli](docs/logo-large.png)
PHP-Extension for compressing content with `Zopfli` a good zlib (gzip, deflate) compatible compressor which produces smallest possible results.

| [![Build Status](https://travis-ci.org/clickalicious/php_zopfli.svg?branch=master)](https://travis-ci.org/clickalicious/php_zopfli) 	| [![Scrutinizer](https://img.shields.io/scrutinizer/g/clickalicious/php_zopfli.svg)](https://scrutinizer-ci.com/g/clickalicious/php_zopfli/) 	| [![clickalicious premium](https://img.shields.io/badge/clickalicious-premium-green.svg?style=flat)](https://www.clickalicious.de/) 	| [![Apache 2.0](https://img.shields.io/hexpm/l/plug.svg)](http://opensource.org/licenses/Apache-2.0) 	|
|---	|---	|---	|---	|
| [![GitHub issues](https://img.shields.io/github/issues/clickalicious/phpmemadmin.svg?style=flat)](https://github.com/clickalicious/php_zopfli/issues) 	| [![Coverage Status](https://coveralls.io/repos/clickalicious/php_zopfli/badge.svg)](https://coveralls.io/r/clickalicious/php_zopfli)  	| [![GitHub release](https://img.shields.io/github/release/clickalicious/php_zopfli.svg?style=flat)](https://github.com/clickalicious/php_zopfli/releases) 	| [![GitHub stars](https://img.shields.io/github/stars/clickalicious/php_zopfli.svg?style=flat)](https://github.com/clickalicious/php_zopfli/stargazers)  	|

## Features

 - Compress content with `Zopfli`
 - Better compression & smaller results - up to 5%!
 - Con: This compressor takes more time (~100x slower!) then average zlib compressing


## Philosophy

`php_zopfli` was designed as a compressor for cases where the time to compress doesn't matter but the results should be as small as possible. I decided to implement `Zopfli` compression for this special case. `Zopfli` produces **up to 5% smaller results** than average zlib compressors out in the wild. `Zopfli` is **up to 100x times slower** to compress the data.


## Installation

Put this single line in your php.ini and put the extension in the same place as the other default extensions
```
extension=php_zopfli.(so|dll)
```

## Config

Optional configure the default number of iterations in your php.ini. Whenever you call zopfliencode() without the 2nd argument the php.ini default value is used instead.
```
[Zopfli]
zopfli.iterations = 5
```


## Example
`php_zopfli` can be used as replacement for *gzip/zlib*-compression. The `Zopfli` compression is **100% compatible with gzip + zlib** so your browser will understand the `Zopfli` output already. Just call *zopfliencode()* instead of *gzencode()*. 

The second argument is the optional iteration counter (a value between 1 and [max?]1000).


```php
<?php

$buffer = 'put some longer story here ...';

/*
 * Use zopfliencode() as replacement for gzencode()
 * 
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


## Documentation

There is currently no documentation.


## Versioning
For a consistent versioning i decided to make use of `Semantic Versioning 2.0.0` http://semver.org. Its easy to understand, very common and known from many other software projects.


## Roadmap

- [ ] General stability improvements and tests


## More Information
`Zopfli` was written by Jyrki Alakuijala, Ph.D. and Lode Vandevenne, M.Sc. from Google Inc.
You will find the projects homepage [here](http://code.google.com/p/zopfli/ "Go to Zopfli homepage") and the whitepaper [here](http://code.google.com/p/zopfli/downloads/detail?name=Data_compression_using_Zopfli.pdf "Download Zopfli whitepaper").


## Participate & share

... yeah. If you're a code monkey too - maybe we can build a force ;) If you would like to participate in either **Code**, **Comments**, **Documentation**, **Wiki**, **Bug-Reports**, **Unit-Tests**, **Bug-Fixes**, **Feedback** and/or **Critic** then please let me know as well!
<a href="https://twitter.com/intent/tweet?hashtags=&original_referer=http%3A%2F%2Fgithub.com%2F&text=%23php_zopfli%20-%20PHP-Extension%20for%20compressing%20data%20with%20%23Zopfli:%20https%3A%2F%2Fgithub.com%2Fclickalicious%2Fphp_zopfli&tw_p=tweetbutton" target="_blank">
  <img src="http://jpillora.com/github-twitter-button/img/tweet.png"></img>
</a>


## Sponsors  
Thanks to our sponsors and supporters:  

| JetBrains | Navicat |
|---|---|
| <a href="https://www.jetbrains.com/phpstorm/" title="PHP IDE :: JetBrains PhpStorm" target="_blank"><img src="https://www.jetbrains.com/phpstorm/documentation/docs/logo_phpstorm.png"></img></a> | <a href="http://www.navicat.com/" title="Navicat GUI - DB GUI-Admin-Tool for MySQL, MariaDB, SQL Server, SQLite, Oracle & PostgreSQL" target="_blank"><img src="http://upload.wikimedia.org/wikipedia/en/9/90/PremiumSoft_Navicat_Premium_Logo.png" height="55" /></a>  |
