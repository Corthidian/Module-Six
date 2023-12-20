#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "colorUtils.h"


static void test_toGrayScale (void**state)
 {
    (void) state;

int r = 100;
    
int g = 150;
    
int b = 200;

assert_int_equal(toGrayScale(&r, &g, &b, AVERAGE), NO_ERROR);
assert_int_equal(r, 150);
assert_int_equal(g, 150);assert_int_equal(b, 150);r = 100;g = 150;b = 200;
assert_int_equal(toGrayScale(&r, &g, &b, LIGHTNESS), NO_ERROR);
assert_int_equal(r, 150);assert_int_equal(g, 150);
assert_int_equal(b, 150);
r = 100;g = 150;
b = 200;
assert_int_equal(toGrayScale(&r, &g, &b, LUMINOSITY), NO_ERROR);
assert_int_equal(r, 134);
assert_int_equal(g, 134);
assert_int_equal(b, 134);
}

static voidtest_toSepia(void **state)
 {
    (void) state;

    
int r = 100;
    
int g = 150;
    
int b = 200;

assert_int_equal(toSepia(&r, &g, &b), NO_ERROR);
assert_int_equal(r, 169);
assert_int_equal(g, 159);
assert_int_equal(b, 129);
}

int main ()

 {
    
const struct CMUnitTest
tests[] =
{
        cmocka_unit_test(test_toGrayScale),
        cmocka_unit_test(test_toSepia),
};

    
return cmocka_run_group_tests(tests, NULL, NULL);
}