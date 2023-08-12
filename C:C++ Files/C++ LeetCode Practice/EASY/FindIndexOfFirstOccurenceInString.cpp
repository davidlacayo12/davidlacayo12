//Problem #28 on Leetcode

#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int hay_len = haystack.length();
        int needle_len = needle.length();
        for(int i = 0; i <= hay_len - needle_len; i++) {
            for(int j = 0 ;j < needle_len; j++) {
                if(needle[j] != haystack[i+j]){break;}
                if(j == needle_len-1) {return i;}
            }
        } 
        return -1;
    }
};