#include "Node.h"

using namespace std;

bool contains(Node *head, int data)
{
    while (head != nullptr)
    {
        if (head->data_ == data)
        {
            return true;
        }
        head = head->next_;
    }
    return false;
}

Node *listSymmetricDifference(Node *first, Node *second) {
  // your code here
    if(first == second) {return nullptr;}

  Node * list = nullptr;
  Node * iterator = first;
  
  while (iterator != nullptr){
    Node *temp = iterator->next_;
    if (!contains(second, iterator->data_) && !contains(list, iterator->data_))
    {
        Node *newNode = new Node;
        newNode->data_ = iterator->data_;
        newNode->next_ = list;
        list = newNode;
    }
    iterator = temp;
}
 iterator = second;

 while(iterator != nullptr) {
    Node *temp = iterator->next_;
    if(!contains(first, iterator->data_) && !contains(list, iterator->data_)){
        Node * newNode = new Node;
        newNode->data_ = iterator->data_;
        newNode->next_ = list;
        list = newNode;
    }
    iterator = temp;
 }

  return list;
}

Node::Node() {
    numNodes++;
}

Node::Node(Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;
