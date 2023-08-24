//Problem #344 in Leetcode 

#include <iostream>
#include <vector>
using std::vector;
using std::swap;

class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0; i < s.size()/2; i++) {
            swap(s[i],s[s.size()-i-1]);
        }
    }
};