#include <stdlib.h>

typedef struct Node {
    int number;
    struct Node* next;
} Node;

typedef struct {
    Node* HEAD;
    Node* TAIL;
} Queue;

Queue* QueueCreate();
void QueueEnqueue(Queue* myQueue, int number);
int QueueIsEmpty(Queue* myQueue);
int QueuePoll(Queue* myQueue);
void QueueClear(Queue* myQueue);
void QueuePrint(Queue* myQueue);
int QueueSize(Queue* myQueue);
int QueueContains(Queue* myQueue, int number);
void QueueReset(Queue* myQueue);