#include "catch_amalgamated.hpp"
#include "verifySol.hpp"
#include <unordered_map>
#include <string>
#include <limits>

// NOTE:  these are not intended as exhaustive tests.
// This should get you started testing.
// However, be aware that if ANY test marked "Required" fails, 
// your score for the portion will be zero, regardless of other considerations.


namespace{

TEST_CASE("RequiredFirst", "[Required]"){
    std::string s1 = "POT";
    std::string s2 = "PAN";
    std::string s3 = "BIB";

    std::unordered_map<char, unsigned> solution = { {'A', 7}, {'B', 5}, 
        {'I', 0}, {'N', 4}, {'O', 3}, {'P', 2}, {'T', 1}
    };

    REQUIRE( verifySolution( s1, s2, s3, solution ) );
}

TEST_CASE("RequiredSecond", "[Required]"){

    std::string s1 = "CAT";
    std::string s2 = "DOG";
    std::string s3 = "PIG";

    std::unordered_map<char, unsigned> solution = { {'A', 5}, {'C', 2}, {'D', 1}, {'G', 6}, {'I', 9}, {'O', 4}, {'P', 3}, {'T', 0} };

    REQUIRE( verifySolution( s1, s2, s3, solution ) );
} // end test two


TEST_CASE("RequiredThird", "[Required]"){

    std::string s1 = "LARRY";
    std::string s2 = "CAREER";
    std::string s3 = "LEGEND";

    std::unordered_map<char, unsigned> solution = { {'L', 5}, {'A', 2}, {'R', 1}, {'Y', 6}, {'C', 9}, {'E', 4}, {'G', 3}, {'N', 0}, {'D', 7} };

    REQUIRE_FALSE( verifySolution( s1, s2, s3, solution ) );
} 


TEST_CASE("WorksWithNumberStrings", "[Not Required]"){

    std::string s1 = "123";
    std::string s2 = "456";
    std::string s3 = "579";

    std::unordered_map<char, unsigned> solution = { {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'9', 9} };

    REQUIRE( verifySolution( s1, s2, s3, solution ) );
} 

TEST_CASE("NoIntegerOverflow", "[Not Required]"){

    std::string s1 = "1";
    std::string s2 = "2";
    std::string s3 = "3";
    

    std::unordered_map<char, unsigned> solution = { {'1', std::numeric_limits<unsigned int>::max()}, {'2', 1}, {'3', 0} };

    REQUIRE( verifySolution( s1, s2, s3, solution ) );
} 
// YOU SHOULD ADD ADDITIONAL TEST_CASE "ERE" H"[CASES]"!! 



} // end namespace
