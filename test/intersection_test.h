#include "../src/intersection.h"
#include <cxxtest/TestSuite.h>
#include <iostream>

class intesection_test : public CxxTest::TestSuite {
public:
    void test_intersection_circles1()
    {
        TS_ASSERT_EQUALS(
                intersection("circle(1 1, 1.5)", "circle(0 0, 1.5)"), 1);
    }
    void test_intersection_circles2()
    {
        TS_ASSERT_EQUALS(intersection("circle(5 5, 1)", "circle(0 0, 1.5)"), 0);
    }
    void test_intersection_circles3()
    {
        TS_ASSERT_EQUALS(intersection("circle(0 0, 1)", "circle(0 0, 1.5)"), 0);
    }
    void test_intersection_triangles1()
    {
        TS_ASSERT_EQUALS(
                intersection(
                        "triangle((-3 -2, -1 0, -3 2, -3 -2))",
                        "triangle((3 -2, 3 2, 1 0, 3 -2))"),
                0);
    }
    void test_intersection_triangles2()
    {
        TS_ASSERT_EQUALS(
                intersection(
                        "triangle((2 0, 1 1, 0 0, 2 0))",
                        "triangle((3 -2, 3 2, 1 0, 3 -2))"),
                1);
    }
    void test_intersection_triangles3()
    {
        TS_ASSERT_EQUALS(
                intersection(
                        "triangle((1 0, 0 1, -1 0, 1 0))",
                        "triangle((2 0, 0 2, -2 0, 2 0))"),
                0);
    }
    void test_intersection_triangle_and_circle1()
    {
        TS_ASSERT_EQUALS(
                intersection(
                        "triangle((2 0, 1 1, 0 0, 2 0))", "circle(0 0, 1.5)"),
                1);
    }
    void test_intersection_triangle_and_circle2()
    {
        TS_ASSERT_EQUALS(
                intersection(
                        "triangle((-3 -2, -3 2, -3 0, -3 -2))",
                        "circle(0 0, 1.5)"),
                0);
    }
    void test_intersection_triangle_and_circle3()
    {
        TS_ASSERT_EQUALS(
                intersection(
                        "triangle((1 0, 0 1, -1 0, 1 0))", "circle(0 0, 1.5)"),
                0);
    }
};