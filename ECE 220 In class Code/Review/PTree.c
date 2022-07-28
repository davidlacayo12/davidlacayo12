#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}t_node;

int countNeg(t_node *node);
int isSame(t_node *node1, t_node *node2);
void mirror(t_node *node);

int main(){

}

int countNeg(t_node *node){
    if(node == NULL) return 0;  //base case 
    //recursive case 
    int sum = countNeg(node->left) + countNeg(node->right);

    if(node->data < 0)
        return sum+1;
    else
        return sum;
}

int isSame(t_node *node1, t_node *node2){
    
}

void mirror(t_node *node){

}