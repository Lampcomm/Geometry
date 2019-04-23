#include "../src/input.h"
#include <cxxtest/TestSuite.h>
#include <iostream>

class input_test : public CxxTest::TestSuite {
public:
    void test_input_circle1()
    {
        TS_ASSERT_EQUALS(circle("circle(0 0, 1.5)"), 1);
    }
    void test_input_circle2()
    {
        TS_ASSERT_EQUALS(circle("circle(-3.2 4.5, 1.5)"), 1);
    }

    void test_input_circle3()
    {
        TS_ASSERT_EQUALS(circle("circle(0 0, -1)"), 2);
    }

    void test_input_circle4()
    {
        TS_ASSERT_EQUALS(circle("cirsdfle(0 0, 1.5)"), 3);
    }

    void test_input_circle5()
    {
        TS_ASSERT_EQUALS(circle("circle(0, 1.5)"), 2);
    }

    void test_input_triangle1()
    {
        TS_ASSERT_EQUALS(triangle("triangle((-3 -2, -1 0, -3 2, -3 -2))"), 1);
    }
    void test_input_triangle2()
    {
        TS_ASSERT_EQUALS(
                triangle("triangle((-3.0 -2, -1 0.5, -3 2, -3 -2))"), 1);
    }
    void test_input_triangle3()
    {
        TS_ASSERT_EQUALS(triangle("triangle((0 0, 0 1, 0 2, 0 0))"), 2);
    }
    void test_input_triangle4()
    {
        TS_ASSERT_EQUALS(
                triangle("tasfxiangle((-3 -2, -1 0, -3 2, -3 -2))"), 3);
    }
    void test_input_triangle5()
    {
        TS_ASSERT_EQUALS(triangle("triangle((-3 2, -1 0, -3 2, -3 -2))"), 2);
    }
    void test_input_triangle6()
    {
        TS_ASSERT_EQUALS(triangle("triangle((-3 -2, -1 0, 2, -3 -2))"), 1);
    }
};