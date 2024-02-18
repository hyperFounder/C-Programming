// Linked List implementation of a queue

#include <stdio.h>
#include <stdlib.h>


typedef struct Node{

    int val;
    struct Node *next;

} Node;

Node *head = NULL;


void enqueue(int val){ // Insert at the beginning
    Node *node = (struct Node *) malloc(sizeof (Node));

    if (head == NULL){
        head = node;
    }else{
        Node *h = head;
        while (h->next!=NULL){
            h = h->next;
        }
        h->next = node;
        node->val = val;
    }
}

void dequeue(){ // Remove from the END

    if (head == NULL){
        printf("Empty List... Exiting");
        exit(-1);
    } else{
        Node *h = head;
        while (h->next->next !=NULL){
            h = h->next;
        }
        h->next = NULL;
    }
}

void print(){
    Node *h = head;
    while (h!=NULL){
        printf("val: %d -> \t", h->val);
        h = h->next;
    }
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);

    print();

    dequeue();

    printf("\n");

    print();
}