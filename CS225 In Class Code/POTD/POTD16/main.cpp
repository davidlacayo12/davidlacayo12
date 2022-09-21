#include "potd.h"
#include <iostream>
using namespace std;

int main() {
  // Test 1: An empty list
  Node * head = NULL;
  cout << stringList(head) << endl;

  // Test 2: A list with exactly one node
  Node second = {14, head};
  cout << stringList(&second) << endl;

  // Test 3: A list with more than one node
  Node third = {65, &second};
  Node fourth = {50, &third};
  Node fifth = {78, &fourth}; 
  cout << stringList(&fifth) << endl;
  return 0;
}
