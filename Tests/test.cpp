#include "pch.h"
#include "../15.23/palindrome.h"

TEST(TestPalindrome, validPalindrome) {
    
    std::vector<int> intVec1 = { 1, 2, 3, 3, 2, 1 };
    std::vector<int> intVec2 = { 1, 2, 3, 2, 1 };
    
    EXPECT_TRUE(palindrome(intVec1));
    EXPECT_TRUE(palindrome(intVec2));
}

TEST(TestPalindrome, invalidPalindrome) {

    std::vector<int> intVec1 = { 1, 2, 3, 4, 2, 1 };
    std::vector<int> intVec2 = { 1, 2, 3, 6, 1 };

    EXPECT_FALSE(palindrome(intVec1));
    EXPECT_FALSE(palindrome(intVec2));
}