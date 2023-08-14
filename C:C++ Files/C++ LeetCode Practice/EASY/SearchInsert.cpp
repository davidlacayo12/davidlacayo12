//Problem #35 on Leetcode 

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) { //Method: Binary Search 
        int len = nums.size();
        int left=0;
        int right = len-1;
        int middle;
        while(left <= right) {
            middle = left + (right - left)/2;
            if(nums[middle] == target) {return middle;}
            if(nums[middle] < target) {left = middle + 1;}
            else {right = middle - 1;}
        }
        return left;
    }
};