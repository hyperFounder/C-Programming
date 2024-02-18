// Circular Doubly Linked List
// 2 pointers. The last pointer points to the front. 
// The front pointer points to the last.
// We have a head and a tail

#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node *head = NULL;
struct Node *tail = NULL;

void insertEnd(int data){
    struct Node* node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    if (head == NULL){
        head = tail = node;
        node->next = node;
        node->prev = node;
    } else{
        tail->next = node;
        node->prev = tail;
        tail = node;
        tail->next = head;
        head->prev = tail;
    }
};

void deleteEnd(){
    if (head == NULL){
        return; // Empty List
    }
    struct Node* t = tail;
    if (head == tail){ // Only 1 Node
        head = tail = NULL;
    }else{
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
    }
}

void print(){
    struct Node *h = head;
    while (h->next !=head){
        printf("%d <-> ", h->data);
        h = h->next;
    }
    printf("%d <-> ", h->data);
}

int main() {
    // Example usage
    insertEnd(3);
    insertEnd(7);
    insertEnd(10);

    // Print the list
    print();
    printf("\n");

    deleteEnd();
    print();
    printf("\n");

    insertEnd(13);
    print();
    printf("\n");

    return 0;
}