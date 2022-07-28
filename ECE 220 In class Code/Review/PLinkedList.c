#include <stdio.h>
#include <stdlib.h>

typedef struct Struct item;
struct Struct{
    int data;
    item *next;
};

int main(){
    item *head = NULL;
    additem(&head, 5);
    additem(&head,10);
    printitem(head);

}

int additem(item **head, int input){
    item *newitem = (item*) malloc(sizeof(item));
    if(newitem == NULL) return 0;
    newitem->data = input;
    newitem->next = *head;
    *head = newitem;
    return 1;


}

void delete_node(item **headpptr, int val){
    while((*headpptr)!= NULL && (*headpptr)->data !=val){
        headpptr = &((*headpptr)->next);   //points to first address of linked list and stores that in headpptr
    }
    if(*headpptr == NULL) return;
    
    item *temp = *headpptr;
    *headpptr = (*headpptr)->next;
    free(temp->data);
    free(temp);

}

void printitem(item *node){
    while(node !=NULL){
        printf("%d", node->data);
        node->next;
    }
}