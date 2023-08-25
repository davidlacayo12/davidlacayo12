//Problem #58 on Leetcode

#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i, counter=0;
        i=s.length()-1;
        while(i>=0 and s[i]==' ')
            i--;
            for(;i>=0;i--){
                if(s[i]==' ' and counter!=0)
                    return counter;
                counter++;
        }
        return counter;
    }
};