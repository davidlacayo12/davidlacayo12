#include "Node.h"

using namespace std;

void sortList(Node **head) {    //used insert sort
  Node * temp = (*head);
  if(*head == NULL) {
      return;
  }
  Node * min_node = nullptr;
  Node * min_prev = nullptr;

  int min_data = (*head)->data_;
  Node * prev = nullptr;

  while(temp != NULL) {
    if(temp->data_ <= min_data) {
        min_data = temp->data_;
        min_prev = prev;
        min_node = temp;
      }
    prev = temp;
    temp = temp->next_;
  }

    if(min_prev != NULL && min_node != NULL) {
        min_prev->next_ = min_node->next_;
        min_node->next_ = *head;
        *head = min_node;
    }
    sortList(&(*head)->next_);

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

