//Problem #217 on Leetcode
//To find this, I used a set, since sets can only have ONE instance of a value

#include <iostream>
#include <set>
#include <vector>

using std::set;
using std::vector;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        int temp = 0;
        for(int i = 0; i < nums.size(); i++) {
            temp = s.size();
            s.insert(nums[i]);
            if(temp == s.size()) {
                return true;
            }
        }
        return false;
    }
};