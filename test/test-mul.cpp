#include "catch.hpp"
#include "BigInt.h"

TEST_CASE( "Multiplication check", "Multiplication check" ) {
    string num;
    num = "11111";
    BigInt obj(num);
    num = "222222";
    BigInt obj2(num);
    REQUIRE( obj.mul(obj2).getVal() == "2469108642" );
    num = "99999";
    BigInt obj3 = num;
    num = "999999";
    BigInt obj4 = num;
    BigInt obj5 = obj3*obj4;
    REQUIRE( obj5.getVal() == "99998900001");
    num = "11111";
    BigInt obj6(num);
    num = "-222222";
    BigInt obj7(num);
    REQUIRE( obj6.mul(obj7).getVal() == "-2469108642" );
    num = "-11111";
    BigInt obj8(num);
    num = "222222";
    BigInt obj9(num);
    REQUIRE( obj8.mul(obj9).getVal() == "-2469108642" );
    num = "-11111";
    BigInt obj10(num);
    num = "-222222";
    BigInt obj11(num);
    REQUIRE( obj10.mul(obj11).getVal() == "2469108642" );
}