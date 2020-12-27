#include "catch.hpp"
#include "BigInt.h"

TEST_CASE( "Division check", "Division check" ) {
    string num;
    long long int num2;
    num = "9756436278597376237";
    BigInt obj(num);
    num2 = 2387628562;
    REQUIRE( obj.div(num2).getVal() == "4086245421" );
    num = "-9756436278597376237";
    BigInt obj2(num);
    num2 = 2387628562;
    REQUIRE( obj2.div(num2).getVal() == "-4086245421" );
    num = "9756436278597376237";
    BigInt obj3(num);
    num2 = -2387628562;
    REQUIRE( obj3.div(num2).getVal() == "-4086245421" );
    num = "-9756436278597376237";
    BigInt obj4(num);
    num2 = -2387628562;
    REQUIRE( obj4.div(num2).getVal() == "4086245421" );
}