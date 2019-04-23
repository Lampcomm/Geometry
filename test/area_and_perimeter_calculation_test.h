#include "../src/area_and_perimeter_calculation.h"
#include <cxxtest/TestSuite.h>
#include <iostream>

class area_and_perimeter_calculation_test : public CxxTest::TestSuite {
public:
    void test_perimeter_calculation1()
    {
        TS_ASSERT_DELTA(perimeter("circle(0 0, 1.5)"), 9.425, 0.0005);
    }
    void test_perimeter_calculation2()
    {
        TS_ASSERT_DELTA(perimeter("circle(1 1, 1.5)"), 9.425, 0.0005);
    }
    void test_perimeter_calculation3()
    {
        TS_ASSERT_DELTA(
                perimeter("triangle((3 -2, 3 2, 1 0, 3 -2))"), 9.657, 0.0005);
    }
    void test_perimeter_calculation4()
    {
        TS_ASSERT_DELTA(
                perimeter("triangle((-3 -2, -1 0, -3 2, -3 -2))"),
                9.657,
                0.0005);
    }
    void test_perimeter_calculation5()
    {
        TS_ASSERT_DELTA(perimeter("circle(5 5, 1)"), 6.283, 0.0005);
    }
    void test_area_calculation1()
    {
        TS_ASSERT_DELTA(
                area("triangle((-3 -2, -1 0, -3 2, -3 -2))"), 4.000, 0.0005);
    }
    void test_area_calculation2()
    {
        TS_ASSERT_DELTA(area("circle(0 0, 1.5)"), 7.069, 0.0005);
    }
    void test_area_calculation3()
    {
        TS_ASSERT_DELTA(area("triangle((1 0, 0 1, -1 0, 1 0))"), 1.000, 0.0005);
    }
    void test_area_calculation4()
    {
        TS_ASSERT_DELTA(
                area("triangle((3 -2, 3 2, 1 0, 3 -2))"), 4.000, 0.0005);
    }
    void test_area_calculation5()
    {
        TS_ASSERT_DELTA(area("circle(1 1, 1.5)"), 7.069, 0.0005);
    }
};