//Problem #7 on LeetCode
#include <iostream>

class Solution {
public:
    int reverse(int x) {
        int r=0;      //remainder variable
        while(x){
         if (r>INT_MAX/10 || r<INT_MIN/10) return 0; //if r is outside 32-bit range then return 0 
         r=r*10+x%10; // find remainder and add its to r
         x=x/10;     // Update the value of x
        } 
        return int(r);  // if r in the 32 bit range then return r
    }
};