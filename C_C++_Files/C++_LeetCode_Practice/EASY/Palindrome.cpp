//Problem #9 on LeetCode
#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        std::string str = std::to_string(x);
        std::string str2 = str;
        int n = str.length();
        for (int i = 0; i < n / 2; i++)
            std::swap(str2[i], str2[n - i - 1]);
        if(str.compare(str2)){
            return false;
        } else {
            return true;
        }
    }
};