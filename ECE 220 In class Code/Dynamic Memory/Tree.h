#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct nodeTag t_node;
struct nodeTag{
    int data;
    t_node *left;
    t_node *right;
};

t_node* NewNode(int data);
void DeleteTree(t_node *node);

// Traverse a tree
void preorder(t_node *node);
void inorder(t_node *node);
void postorder(t_node *node);


// Helper functions to print out a tree
void padding(char ch, int n);
void printTree(t_node *node, int level);

// BST
t_node* BSTInsert(t_node *node, int data);
t_node* BSTSearch(t_node *node, int key);

t_node* FindMin(t_node *node);
t_node* FindMax(t_node *node);
int getHeight(t_node *node);