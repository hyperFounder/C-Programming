#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  struct Node *next;
}Node;

Node* head = NULL;

pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;

void insert(int data){
  Node *node = (Node *)malloc(sizeof(Node));
  pthread_rwlock_wrlock(&rwlock);

  (*node).next = head;
  head = node;
  (*node).data = data;
  pthread_rwlock_unlock(&rwlock);
}

void deleteEnd(){
  pthread_rwlock_wrlock(&rwlock);
  Node* h = head;
  while (h->next->next != NULL){
    h = h->next;
  }
  h->next = NULL;
  pthread_rwlock_unlock(&rwlock);
}

void freeList(){
  pthread_rwlock_wrlock(&rwlock);

  Node* h = head;
  Node* next;
  while (h != NULL){
    next = h->next;
    free(h);
    h = next;
  }
  head = NULL;
  pthread_rwlock_unlock(&rwlock);

}

void print(){
  pthread_rwlock_rdlock(&rwlock);
  Node *h = head;
  while (h!=NULL){
    printf("%d -> ", h->data);
    h = (*h).next;
  }

  pthread_rwlock_rdlock(&rwlock);
}

int main() {
    insert(3);
    insert(7);
    insert(10);
    deleteEnd();
    // Concurrent read
    pthread_t readerThread;
    pthread_create(&readerThread, NULL, (void*)&print, NULL);
    // Concurrent write
    insert(15);
    // Wait for the reader thread to finish
    pthread_join(readerThread, NULL);
    // Print the modified list
    print();

    // freeList();
    pthread_rwlock_destroy(&rwlock);
    return 0;
}
