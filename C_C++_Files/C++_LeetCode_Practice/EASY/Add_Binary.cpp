//Problem #67 on Leetcode
/*
* In order to solve this problem, we must think back to ECE 120/220/385 and remember the architecture of an adder
* Carry bit, and sum bit, and it goes on and on in a linear fashion until the final string of bits outputted
*/

#include <iostream>
#include <string>

using std::string;
using std::to_string;

class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        while(i>=0 || j>=0) {
            int sum = carry;
            if(i>=0) {sum+=a[i--] - '0';}
            if(j>=0) {sum+=b[j--] - '0';}
            carry = sum > 1 ? 1 : 0;
            ans += to_string(sum % 2);
        }
        if(carry) {ans += to_string(carry);}
        reverse(ans.begin(), ans.end());
        return ans;

    }
};