//Problem #20 on Leetcode
//For valid parenthesis, use a stack

#include <iostream>
#include <string>
#include <stack>

using std::string;
using std::stack;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            if( (s[i] == '(') || (s[i] == '[') || (s[i] == '{') ) {
                st.push(s[i]);
            } else {
                if(st.empty() || (s[i] == ')' && st.top() != '(') || (s[i] == ']' && st.top() != '[') 
                                                                    || (s[i] == '}' && st.top() != '{') ) {
                    return false;
                } else {
                    st.pop();
                } 
            }
        }
        return st.empty();
    }    
};