// Your code here
#include <iostream>
using namespace std;

string getFortune(const string &s) {
    string fortunes[] = {"As you wish!", "Nec spe nec metu!", 
    "Do, or do not. There is no try", "This fortune intentionally left blank",
    "Amor Fati!"};

    return fortunes[s.length()%5];
}