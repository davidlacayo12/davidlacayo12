//Problem #268 on Leetcode
//Bad memory and runtime, but works and is unique

#include <iostream>
#include <vector>

using std::vector;
using std::sort;
using std::abs;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int temp = nums[0];
        int n = nums.size();
        bool flag = 0;
        if(temp == 0) {flag = 1;}       //if first number is zero, mark for later

        if(n == 1) {return abs(temp-1);}
        for(int i = 1; i <n; i++) {
            if(nums[i] - 1 != temp) {
                return nums[i] - 1;
            } else {
                temp = nums[i];
            }
        }
        if(flag) {  //if first number is 0, missing at end of vector
            return nums[n-1]+1;
        }
        return 0;   //else, we are missing zero at the start
    }
};