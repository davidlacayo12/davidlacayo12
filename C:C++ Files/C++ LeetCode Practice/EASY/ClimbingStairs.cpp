//Problem #70 on Leetcode
//Down-Up method gone over in ECE220

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) {return n;}
        vector<int> v(n+1);
        v[0] = 0;
        v[1] = 1;
        v[2] = 2;
        for(int i =3; i <= n; i++) {
            v[i] = v[i-1] + v[i-2];
        }
        return v[n];
    }
};