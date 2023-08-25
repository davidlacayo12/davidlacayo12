//Problem #26 on Leetcode
#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i-1]){
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};

int main() {
    int[] nums = [...]; // Input array
    int[] expectedNums = [...]; // The expected answer with correct length

    int k = removeDuplicates(nums); // Calls your implementation

    assert k == expectedNums.length;
    for (int i = 0; i < k; i++) {
        assert nums[i] == expectedNums[i];
    }
}