#include "catch.hpp"
#include "BigInt.h"

TEST_CASE( "Other functionality check", "Other functionality check" ) {
    string num;
    int num2;
    long long int num3;
    num = "11111";
    BigInt obj(num);
    BigInt obj2 = -obj;
    REQUIRE( obj2.getVal() == "-11111" );
    REQUIRE( obj2.abs().getVal() == "+11111");
    num2 = 20;
    BigInt obj3 = BigInt::fact(num2);
    REQUIRE( obj3.getVal() == "2432902008176640000");
    num3 = 1000000007;
    REQUIRE (obj3.mod(num3).getVal() == "146326063");
    REQUIRE ((obj3 % num3).getVal() == "146326063");
    REQUIRE (BigInt::pow("5",10).getVal() == "9765625" );
}