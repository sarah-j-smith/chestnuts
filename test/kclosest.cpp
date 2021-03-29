#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../kclosest/kclosest.cpp"

TEST_CASE("testing binary runs") {

    vector< vector< int > > input {
        { 1, 3 },
        { -2, 2 }
    };
    auto output = Solution().kClosest(input, 1);
    CHECK(output[0] == vector<int>({ -2, 2 }) );
}