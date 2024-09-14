#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/Queue.h"

Queue* QueueCreate() {
    Queue* myQueue = (Queue*)malloc(sizeof(Queue));

    if(myQueue == NULL) {
        printf("ERRO: Falha ao alocar memória\n");
        exit(1);
    }

    myQueue->HEAD = myQueue->TAIL = NULL;
    return myQueue;
}

void QueueEnqueue(Queue* myQueue, int number) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    if(newNode == NULL) {
        printf("ERRO: Falha ao alocar memória\n");
        exit(1);
    }

    newNode->number = number;
    newNode->next = NULL;

    if(myQueue->TAIL != NULL)
        myQueue->TAIL->next = newNode;
    else
        myQueue->HEAD = newNode;

    myQueue->TAIL = newNode;
}

int QueueIsEmpty(Queue* myQueue) {
    return (myQueue->HEAD == NULL);
}

int QueueSize(Queue* myQueue) {
    int size = 0;

    Node* currentNode = myQueue->HEAD;
    while(currentNode != NULL) {
        size++;
        currentNode = currentNode->next;
    }

    return size;
}

int QueuePoll(Queue* myQueue) {
    if(QueueIsEmpty(myQueue)) {
        printf("ERRO: Não é possível remover um elemento de uma fila vazia\n");
        exit(1);
    }

    int number = myQueue->HEAD->number;
    Node* currentNode = myQueue->HEAD;
    myQueue->HEAD = currentNode->next;

    if(myQueue->HEAD == NULL)
        myQueue->TAIL = NULL;

    free(currentNode);
    return number;
}

void QueueClear(Queue* myQueue) {   
    Node* currentNode = myQueue->HEAD;

    while(currentNode != NULL) {
        Node* nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }

    free(myQueue);
}

void QueueReset(Queue* myQueue) {   
    Node* currentNode = myQueue->HEAD;

    while(currentNode != NULL) {
        Node* nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }

    myQueue->HEAD = myQueue->TAIL = NULL;
}

void QueuePrint(Queue* myQueue) {
    if(QueueIsEmpty(myQueue)) {
        printf("ERRO: Não é possível imprimir elementos de uma fila vazia\n");
        exit(1);
    }

    char result[100] = "[";

    Node* currentNode = myQueue->HEAD;
    while(currentNode != NULL) {
        Node* nextNode = currentNode->next;

        char buffer[20];
        sprintf(buffer, "%d", currentNode->number);

        if(currentNode != myQueue->HEAD) {
            strcat(result, ", ");
        }

        strcat(result, buffer);

        currentNode = nextNode;
    }

    strcat(result, "]\n");

    printf("%s", result);
}

int QueueContains(Queue* myQueue, int number) {
    if(QueueIsEmpty(myQueue)) {
        return 0;
    }

    Node* currentNode = myQueue->HEAD;

    while(currentNode != NULL) {
        if(currentNode->number == number)
            return 1;
        else
            currentNode = currentNode->next;
    }
    return 0;
}
