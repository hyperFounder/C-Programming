#include <stdio.h>
#include <stdlib.h>


struct Node {
    int val;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

void insert_beginning(int val){
    struct Node *node = (struct Node *) malloc(sizeof (struct Node));

    if (head!=NULL){
        head->prev = node;
    }
    node->next = head;
    node->prev = NULL;

    node->val = val;
    head = node;
}

void insert_last(int val){
    struct Node *node = malloc(sizeof (struct Node));

    if (head == NULL){
        head = node;
    }else{
        struct Node *h = head;

        while (h->next != NULL){
            h = h->next;
        }
        h->next = node;
        node->prev= h;
        node->next = NULL;
    }
}


void delete_begining(){
    if (head == NULL){
        printf("Error... Exiting");
        exit(-1);
    } else{
        head = head->next;
        if (head != NULL){
            head->prev = NULL;
        }
    }
}

void delete_end(){
    if (head == NULL){
        printf("Error... Exiting");
        exit(-1);
    } else{
        struct Node *h = head;
        while (h->next != NULL){
            h = h->next;
        }
        h->prev->next = NULL;
        free(h);
    }
}


void print(){
    struct Node *h = head;
    while (h!=NULL){
        printf("<-%d-> ", h->val);
        h = h->next;
    }
}

int main(){

    insert_beginning(3);
    insert_beginning(7);
    insert_beginning(11);

    print();

    delete_end();

    printf("\n");

    print();
    return 0;
}