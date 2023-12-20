#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "colorUtils.h"

static void test_rgbToCMYK(void **state) {
    (void) state;

    double c, m, y, k;

    assert_int_equal(rgbToCMYK(255, 0, 0, &c, &m, &y, &k), 0);
    assert_true(fabs(c - 0.0) < 0.001);
    assert_true(fabs(m - 1.0) < 0.001);
    assert_true(fabs(y - 1.0) < 0.001);
    assert_true(fabs(k - 0.0) < 0.001);

}

static void test_cmykToRGB(void **state) {
    (void) state;

    int r, g, b;

    assert_int_equal(cmykToRGB(0.0, 1.0, 1.0, 0.0, &r, &g, &b), 0);
    assert_int_equal(r, 255);
    assert_int_equal(g, 0);
    assert_int_equal(b, 0);

}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_rgbToCMYK),
        cmocka_unit_test(test_cmykToRGB),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
