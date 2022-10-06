#include "TreeNode.h"

#include <cstddef>
#include <iostream>
using namespace std;

TreeNode::TreeNode() : left_(NULL), right_(NULL) { }

int maxDepth(TreeNode * node) {
  if(node == NULL) {return -1;}
  return 1 + std::max(maxDepth(node->left_), maxDepth(node->right_));
}

int TreeNode::getHeight() {
  return maxDepth(this);
}

