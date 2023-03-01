// Copyright[2023]<Copyright Arthea Valderrama>
#include <iostream>

#include "Sokoban.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(testStepINSTR1) {
    Matrix matrix(10, 10);
    BOOST_REQUIRE_EQUAL(matrix.height(), 10);
    BOOST_REQUIRE_EQUAL(matrix.width(), 10);
}

BOOST_AUTO_TEST_CASE(testStepINSTR2) {
    Matrix matrix(1, 1);
    BOOST_REQUIRE_EQUAL(matrix.setheight(10), 10);
    BOOST_REQUIRE_EQUAL(matrix.setwidth(10), 10);
}
