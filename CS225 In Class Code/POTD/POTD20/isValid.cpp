#include <string>
#include <stack>

using namespace std;

bool isValid(string input) {
    stack<char> st;
    for(const auto chr: input) {
        if(chr == '(') {
            st.push(chr);
        }

        else if(chr == '['){
            st.push(chr);
        }

        else if(chr == '{') {
            st.push(chr);
        }

        else if(chr == ')') {
            if(st.empty() || st.top()!='(') {return false;}
            st.pop();
        }

        else if(chr == ']') {
            if(st.empty() || st.top()!='[') {return false;}
            st.pop();
            
        } 

        else if(chr == '}') {
            if(st.empty() || st.top()!='{') {return false;}
            st.pop();
            
        }

    }
    return st.empty();
}