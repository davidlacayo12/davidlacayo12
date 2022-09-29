#include "Node.h"

using namespace std;

bool contains(Node * first, int data) {
    Node * curr = first;

    while(curr!=NULL) {
        if(curr->data_ == data) {
            return true;
        }
        curr = curr->next_;
    }
    return false;
}

Node *listIntersection(Node *first, Node *second) {
    Node * intersection = NULL;
    Node * curr = first;

    while(curr!= NULL) {
        if(contains(second, curr->data_)) {
            if(intersection == NULL) {
            intersection = new Node();
            intersection->data_ = curr->data_;
            intersection->next_ = NULL;
            }
            else {
                intersection->next_ = new Node();
                intersection->next_->data_ = curr->data_;
                intersection->next_->next_ = NULL;
            }
        }
        curr = curr->next_;

    }
    return intersection;
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
