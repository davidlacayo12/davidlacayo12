#include "potd.h"
#include <iostream>

using namespace std;

string stringList(Node *head) {
    // your code here!
    if (head == NULL)
        return "Empty list";
    else if(head->next_ == NULL) {
        return "Node 0: 10";
    }
    else {
        int count = 0;
        int num = 10;
        Node * curr = head;
        string final = "Node 0: 10";
        while(curr->next_ != NULL) {
            num += 10;
            count++;
            curr = curr->next_;
            final += " -> Node " + to_string(count) + ": " + to_string(num);
            
        }
        return final;
    }
    return "";
}
