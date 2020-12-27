#include "catch.hpp"
#include "BigInt.h"

TEST_CASE( "Initialization check", "Initialization check" ) {
    string num;
    num = "123456";
    BigInt obj(num);
    REQUIRE( obj.getVal() == num );
    num = "12345678909876543212345";
    BigInt obj2 = num;
    REQUIRE( obj2.getVal() == num);
    num = "-123456";
    BigInt obj3(num);
    REQUIRE( obj3.getVal() == num );
}