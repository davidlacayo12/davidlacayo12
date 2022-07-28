#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StudentStruct{
int UIN;
char *netid;
float GPA;
struct StudentStruct *next;
}node;

void insert_head(node **headpptr, node *data);
void printStudents(node *cursor);
void insert_sorted_GPA(node **headpptr, node *data);
void insert_head_base(node *baseptr, node*data);
void delete_all(node **headpptr);

void push(node **headpptr, node *data);         //inserts a new head to list, like insert_head
void pop(node **headpptr);                   //pops head off of list 
void enqueue(node **headpptr, node *data);  //queue  -> start from head to traverse
void dequeue(node **headpptr);          //double ended queue    ->can traverse starting from head or tail




int main(){

    node *headptr = NULL;
    node temp;
    //first node
    temp.UIN = 1234;
    //reserve heap mem (Without actual contents)
    temp.netid = (char*) malloc(sizeof("dlacayo2")+1);     //+1 for null character
    strcpy(temp.netid, "dlacayo2");
    temp.GPA = 3.4;
    temp.next = NULL;
    insert_sorted_GPA(&headptr, &temp);
    printStudents(headptr);

    delete_all(&headptr);

}

void insert_head(node **headpptr, node *data){
    node *temp = (node*) malloc(sizeof(node));
    *temp = *data;
    temp->next = *headpptr;
    *headpptr = temp;
}

void insert_head_base(node *baseptr, node*data){            //another method for head pointer 
    node *temp = (node*) malloc(sizeof(node));
    *temp = *data;
    temp->next = baseptr->next;
    baseptr->next = temp;
}

void insert_sorted_GPA(node **headpptr, node *data){
    node *temp = (node*) malloc(sizeof(node));
    *temp = *data;
    while( ((*headpptr)->GPA > (temp->GPA)) && (*headpptr != NULL) ){            //traverse 
        headpptr = (*headpptr)->next; 
    }
    temp->next = (*headpptr);
    *headpptr = temp;

}

void delete_all(node **headpptr){
    node *temp;
    while((*headpptr) != NULL){
        free((*headpptr)->netid);     //frees memory associated with current NETID so there is no memory overflow, then we can delete the pointer to this data
        temp = (*headpptr)->next;       //temporary stores next item in list in a temp pointer to restore the head after deletion 
        free(*headpptr);    //del the head 
        (*headpptr) = temp;
    }

}

void printStudents(node *cursor){
    printf("UIN netid GPA\n");

    while(cursor != NULL){
        printf("%d %s %f\n", cursor->UIN, cursor->netid, cursor->GPA);
        cursor = cursor->next;
    }
}

//Implement the stack using push() and pop()

void push(node **headpptr, node *data){
    node *temp = (node*) malloc(sizeof(node));
    *temp = *data;
    temp->next = *headpptr;
    *headpptr = temp;   
}

void pop(node **headpptr){
    node *next;
    if(*headpptr == NULL){
        printf("Stack is empty\n");
        return;
    }
    free((*headpptr)->netid);
    next = (*headpptr)->next;
    free(*headpptr);
    *headpptr = next;
}

//Queue by linked list 

void enqueue(node **headpptr, node *data){
    node *temp = (node*) malloc(sizeof(node));

    *temp = *data;
    temp->next = NULL;
    while(*headpptr != NULL){   
        headpptr = &((*headpptr)->next); //traverse
    }
    *headpptr = temp;

}

void dequeue(node **headpptr){
    node *next;
    if(*headpptr == NULL){
        printf("Stack is empty\n");
        return;
    }
    free((*headpptr)->netid);
    next = (*headpptr)->next;
    free(*headpptr);
    *headpptr = next;
}
