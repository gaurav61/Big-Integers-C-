#include "catch.hpp"
#include "BigInt.h"

TEST_CASE( "Addition check", "Addition check" ) {
    string num;
    num = "11111";
    BigInt obj(num);
    num = "222222";
    BigInt obj2(num);
    REQUIRE( obj.add(obj2).getVal() == "233333" );
    num = "99999";
    BigInt obj3 = num;
    num = "999999";
    BigInt obj4 = num;
    BigInt obj5 = obj3+obj4;
    REQUIRE( obj5.getVal() == "1099998");
    num = "11111";
    BigInt obj6(num);
    num = "-222222";
    BigInt obj7(num);
    REQUIRE( obj6.add(obj7).getVal() == "-211111" );
    num = "-11111";
    BigInt obj8(num);
    num = "222222";
    BigInt obj9(num);
    REQUIRE( obj8.add(obj9).getVal() == "211111" );
    num = "-11111";
    BigInt obj10(num);
    num = "-222222";
    BigInt obj11(num);
    REQUIRE( obj10.add(obj11).getVal() == "-233333" );
}