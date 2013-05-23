ruby-geo-normalize
==================

Installation
-----------

GeoNormalize is available through [Rubygems](http://rubygems.org/gems/geo_normalize) and can be installed via:

```
$ gem install geo_normalize
```

Introduction
------------

``` ruby
require "geo_normalize"

# normalize utf8 strings
GeoNormalize.normalize("Gaspésie–Îles-de-la-Madeleine")
=> "gaspesieilesdelamadeleine"
```
