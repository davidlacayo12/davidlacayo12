#include "potd.h"
#include <iostream>

using namespace std;

void insertSorted(Node **head, Node *item) {
  // your code here!
  if(*head == NULL) {
    *head = item;
    return;
  }

  if((*head)->data_ >= item->data_) {
    item->next_ = *head;
    (*head) = item;
    return;
  }
    
  Node * temp_head = (*head);
  while((temp_head->next_ != NULL) && (item->data_ > temp_head->next_->data_)) {
      temp_head = temp_head->next_;
  }

  Node * temp = temp_head->next_;
  item->next_ = temp;
  temp_head->next_ = item;


}
