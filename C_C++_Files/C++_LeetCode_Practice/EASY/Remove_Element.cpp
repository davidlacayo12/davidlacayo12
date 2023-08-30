//Problem #27 on Leetcode
#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator it;
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
            if(*it == val) {
                nums.erase(it);
                it--;
            }
        }
        
        return nums.size();
    }
};