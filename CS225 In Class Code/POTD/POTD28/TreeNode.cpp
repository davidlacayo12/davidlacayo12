#include "TreeNode.h"
#include <iostream>

TreeNode * deleteNode(TreeNode* root, int key) {
  // your code here
  if(root == NULL) {
    return root;
  }
  else if(root->val_ > key) {
    root->left_ = deleteNode(root->left_, key);
  }
  else if(root->val_ < key) {
    root->right_ = deleteNode(root->right_, key);
  }

  else {
    if(root->left_ == NULL) {
      TreeNode * temp = root->right_;
      delete root;
      return temp;
    }
    if(root->right_ == NULL) {
      TreeNode * temp = root->left_; 
      delete root;
      return temp;
    }
    TreeNode* ios = root->right_;
    while(ios->left_ != NULL) {
      ios = ios->left_;
    }
    root->val_ = ios->val_;
    root->right_ = deleteNode(root->right_, ios->val_);
  }
  
  return root;
}

void inorderPrint(TreeNode* node)
{
    if (!node)  return;
    inorderPrint(node->left_);
    std::cout << node->val_ << " ";
    inorderPrint(node->right_);
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
