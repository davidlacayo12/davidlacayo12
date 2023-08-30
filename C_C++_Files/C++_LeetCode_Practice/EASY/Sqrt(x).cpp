//Problem #69 on Leetcode
//Good with memory, bad with runtime

#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        int temp = 0;
        int curr = 0;
        if(x == 0 || x == 1) {return x;}
        for(int i = 0; i <= 46340; i++) {
            curr = i*i;
            if(curr == x) {
                return i;
            } else if(curr < x) {
                temp = i;
            } else {
                if(round(curr) == x) {
                    return i;
                } else {
                    return temp;
                }
            }
        }
        return 46340;
    }
};