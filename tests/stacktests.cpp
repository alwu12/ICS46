#include "catch_amalgamated.hpp"
#include "postfixCalc.hpp"
#include "LLStack.hpp"
#include <unordered_map>
#include <string>

// NOTE:  these are not intended as exhaustive tests.
// This should get you started testing.
// However, be aware that if ANY test marked "Required" fails, 
// your score for the portion will be zero, regardless of other considerations.


namespace{


// And some tests for the linked list based stack and the associated calculator.
    // VERY IMPORTANT:  if your LLStack is not templated, or if 
    //      it is not linked-list based, your score for this project
    //      will be zero.  Be sure your LLStack compiles and runs 
    //      with non-numeric data types.  A char is a numeric type.
    // 

TEST_CASE("RequiredStackTest1", "[Required]")
{
    LLStack<int> a;
    a.push(5);
    REQUIRE( a.top() == 5 );
}

TEST_CASE("RequiredStackTest2", "[Required]")
{
    LLStack<int> a;
    a.push(5);
    a.push(3);
    REQUIRE( a.top() == 3 );
}


TEST_CASE("RequiredStackTest3", "[Required]")
{
    LLStack<int> a;
    a.push(5);
    a.push(3);
    a.pop();
    REQUIRE( a.top() == 5 );
}


TEST_CASE("RequiredStackTest4", "[Required]")
{
    LLStack<int> a;
    REQUIRE_THROWS_AS( a.top(), StackEmptyException );
}





/*
// YOU SHOULD ADD ADDITIONAL TEST_CASE "ERE" H"[CASES]"!! 



TEST_CASE("RequiredCalcTest1", "[Required]")
{
    const std::vector<std::string> EXPRESSION = {
        "5", "3", "*"
    };
    REQUIRE( postfixCalculator(EXPRESSION) == 15);
}

TEST_CASE("RequiredCalcTest2", "[Required]")
{
    const std::vector<std::string> EXPRESSION = {
        "5", "3", "2", "-", "*"
    };
    REQUIRE( postfixCalculator(EXPRESSION) == 5);
    
}

TEST_CASE("RequiredCalcTest3", "[Required]")
{
    const std::vector<std::string> EXPRESSION = {
        "5", "3", "2", "-"
    };
    REQUIRE_THROWS( postfixCalculator(EXPRESSION) );
    
}

// You can fail this test and still get partial credit from others that pass. 
// Of course, I would recommend you get this one to pass, too...
// Note that the group name is "CalcTest" and not "Required."
TEST_CASE("AdditionalTest4", "[CalcTest]")
{
    const std::vector<std::string> EXPRESSION = {
        "5", "3", "*", "20", "*"
    };
    REQUIRE( postfixCalculator(EXPRESSION) == 300);
    
}
*/

//check that copy constructor is a deep copy and not shallow
TEST_CASE("ProperDeepCopyConstructor_LLStack", "[LLStack]")
{
    LLStack<int> x;
    x.push(5);
    LLStack<int> y(x);
    x.push(10);
    REQUIRE( x.top() == 10 );
    REQUIRE( y.top() == 5 );
}

//check that copy constructor is a deep copy and not shallow
TEST_CASE("ProperDeepCopyOperator_LLStack", "[LLStack]")
{
    LLStack<int> x;
    x.push(5);
    LLStack<int> y = x;
    x.push(10);
    REQUIRE( x.top() == 10 );
    REQUIRE( y.top() == 5 );
}

TEST_CASE("CopyOperatorCanCopyItself_LLStack", "[LLStack]")
{
    LLStack<int> x;
    x.push(5);
    x = x;
    REQUIRE( x.top() == 5 );
}

TEST_CASE("TopWorksForConstAndMutable", "[LLStack]")
{
    LLStack<int> x;
    x.push(5);
    const LLStack<int> y = x;
    x.push(10);
    REQUIRE( x.top() == 10 );
    REQUIRE( y.top() == 5 );
}


TEST_CASE("PopIsDeletingProperly", "[LLStack]")
{
    LLStack<int> x;
    x.push(5);
    x.push(10);
    x.pop();
    REQUIRE( x.top() == 5 );
    REQUIRE( x.size() == 1 );

}

TEST_CASE("SizeDoesNotMakeYouLoseHead", "[LLStack]")
{
    //check to see that when iterating in size, i am not leaking memory
    LLStack<int> x;
    x.push(5);
    REQUIRE( x.size() == 1 );
    REQUIRE( x.size() == 1 );
}



} // end namespace
