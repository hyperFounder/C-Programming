#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    int priority;
} Node;

// Singly Linked List

int enqueue(Node **queue, Node* p){
    Node *h = *queue;
    Node *prev = NULL;

    while (h != NULL && h->priority > p->priority){
        prev = h;
        h = h->next;
    }
    
    if (prev == NULL){
        // Insert at the beginning
        p->next = *queue;
        *queue = p;
    } else {
        // Insert in the middle or at the end
        prev->next = p;
        p->next = h;
    }

    return 1; // Successful Enqueue
}

void printQueue(Node* queue) {
    while (queue != NULL) {
        printf("(%d, %d) ", queue->data, queue->priority);
        queue = queue->next;
    }
    printf("\n");
}

int main() {
    Node* priorityQueue = NULL;

    // Example usage
    Node* node1 = (Node*)malloc(sizeof(Node));
    node1->data = 10;
    node1->priority = 2;
    node1->next = NULL;

    Node* node2 = (Node*)malloc(sizeof(Node));
    node2->data = 20;
    node2->priority = 1;
    node2->next = NULL;

    Node* node3 = (Node*)malloc(sizeof(Node));
    node3->data = 30;
    node3->priority = 3;
    node3->next = NULL;

    enqueue(&priorityQueue, node1);
    enqueue(&priorityQueue, node2);
    enqueue(&priorityQueue, node3);

    // Print the priority queue
    printQueue(priorityQueue);

    // Clean up
    while (priorityQueue != NULL) {
        Node* temp = priorityQueue;
        priorityQueue = priorityQueue->next;
        free(temp);
    }

    return 0;
}
