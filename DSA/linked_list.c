#include <stdio.h>
#include <stdlib.h>

struct Node{
    int val;
    struct Node *next;
};

struct Node *head = NULL;


void insert_beginning(int val){
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->next = head;
    head = node;
    node->val = val;
}

void insert_end(int val){

    struct Node *node = (struct Node *) malloc(sizeof (struct Node));

    if (head == NULL){
        head = node;
    }
    else{
        struct Node *h = head;
        while (h->next!=NULL){
            h = h->next;
        }
        h->next = node;
        node->val = val;
    }

}

void print(){
    struct Node *h = head;
    while (h!=NULL){
        printf("val: %d -> \t", h->val);
        h = h->next;
    }
}

void delete_beginning(){
    if (head == NULL){
        printf("Empty List... Exiting");
        exit(-1);
    }
    head = head->next;
}

void delete_end(){
    if (head == NULL){
        printf("Empty List... Exiting");
        exit(-1);
    }
    struct Node *h = head;
    while (h->next->next != NULL){
        h = h->next;
    }
    h->next = NULL;
}


int main(){
    // Example: Inserting nodes at the beginning
    insert_beginning(3);
    insert_beginning(7);
    insert_beginning(11);

    print();

    delete_beginning();
    printf("\n");
    print();

    printf("\n");

    delete_end();

    print();

    insert_end(20);

    printf("\n");

    print();



    return 0;
}