#include <ruby.h>
#include <iconv.h>

VALUE GeoNormalize = Qnil;

void Init_geo_normalize();
VALUE method_geo_normalize(VALUE self, VALUE str);
char *geo_normalize(char *str, iconv_t cd);

void Init_geo_normalize() {
    GeoNormalize = rb_define_module("GeoNormalize");
    rb_define_singleton_method(GeoNormalize, "normalize", method_geo_normalize, 1);
}

VALUE method_geo_normalize(VALUE self, VALUE str) {
    if (TYPE(str) != T_STRING)
	rb_raise(rb_eArgError, "normalize needs a string parameter");

    size_t length = RSTRING_LEN(str);
    char *buffer = malloc(length+1);
    memcpy(buffer, RSTRING_PTR(str), length);
    buffer[length] = 0;

    char *result = geo_normalize(buffer, NULL);

    free(buffer);

    if (result == NULL)
	rb_raise(rb_eStandardError, "geo_normalize call failed");

    VALUE ret = rb_str_new2(result);

    free(result);

    return ret;
}
