#include <stdio.h>
#include <stdlib.h>

#include "../include/Queue.h"

int fifoPageReplacement(Queue* pagesQueue, Queue* memoryQueue, int frames) {
    QueueReset(memoryQueue);
    int pageFaults = 0;

    while(pagesQueue->HEAD != NULL) {
        int number = QueuePoll(pagesQueue);

        if(QueueSize(memoryQueue) < frames) {

            if(!QueueContains(memoryQueue, number)) {

                QueueEnqueue(memoryQueue, number);
                pageFaults++;
            }
        } else {

            if(!QueueContains(memoryQueue, number)) {
                QueuePoll(memoryQueue);
                QueueEnqueue(memoryQueue, number);
                pageFaults++;
            }
        }
    }
    return pageFaults;
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void promptMenu() {
    clearScreen();
    printf("\n===============================================\n");
    printf("      ** Substituição de Páginas FIFO **       \n");
    printf("===============================================\n");

    printf("\t1. Adicionar Sequência de Páginas\n");
    printf("\t2. Imprimir Sequência de Páginas\n");
    printf("\t3. Limpar a Sequência de Páginas\n");
    printf("\t4. Rodar Algoritmo FIFO\n");
    printf("\t0. Sair\n");
    printf("===============================================\n");
    printf("Escolha uma opção: ");
}

void promptAddPages(Queue* myQueue) {
    clearScreen();

    int number;
    printf("\n==================================================\n");
    printf("        ** Adicionar Sequência de Páginas **     \n");
    printf("==================================================\n");
    printf("Digite os números separados por Espaço.\n");
    printf("Pressione Enter quando terminar:\n");

    while(1) {
        scanf("%d", &number);

        QueueEnqueue(myQueue, number);

        if(getchar() == '\n')
            break;
    }

    printf("\nSequência de páginas adicionada com sucesso.\n");
    printf("\nPressione Enter para voltar ao menu...\n");
    getchar();
}

void promptPrintPages(Queue* myQueue) {
    clearScreen();
    printf("\n===============================================\n");
    printf("      ** Imprimir Sequência de Páginas **      \n");
    printf("===============================================\n");

    if(!QueueIsEmpty(myQueue)) {
        QueuePrint(myQueue);
    } else {
        printf("ERRO: A sequência de páginas está vazia.\n");

    }

    printf("\nPressione Enter para voltar ao menu...\n");
    getchar();
}

void promptExit(Queue* myQueue) {
    clearScreen();
    printf("\n===============================================\n");
    printf("            ** Saindo do Aplicativo **         \n");
    printf("===============================================\n");

    QueueClear(myQueue);
    exit(0);
}

void promptFifoPageReplacement(Queue* pagesQueue, Queue* memoryQueue) {
    clearScreen();
    printf("\n===============================================\n");
    printf("             ** Algoritmo FIFO **              \n");
    printf("===============================================\n");

    if(!QueueIsEmpty(pagesQueue)) {
        int frames;
        printf("Digite o número de frames da memória: ");
        scanf("%d", &frames);

        getchar();

        printf("\nTotal de falhas na página: %d\n", fifoPageReplacement(pagesQueue,memoryQueue, frames));
        printf("Estado final da memória: ");
        QueuePrint(memoryQueue);
    } else 
        printf("ERRO: A sequência de páginas está vazia.\n");

    printf("\nPressione Enter para voltar ao menu...\n");
    getchar();
}

void promptClearPages(Queue* pagesQueue) {
    clearScreen();
    printf("\n===============================================\n");
    printf("        ** Limpa Sequência de Páginas **      \n");
    printf("===============================================\n");

    if(!QueueIsEmpty(pagesQueue)) {
        QueueReset(pagesQueue);
        printf("Limpeza da sequência de páginas realizada com sucesso.\n");
    } else 
        printf("ERRO: A sequência de páginas está vazia.\n");
    
    printf("\nPressione Enter para voltar ao menu...\n");
    getchar();
}

int main() {
    Queue* pagesQueue = QueueCreate();
    Queue* memoryQueue = QueueCreate();
    
    int option;
    do {
        promptMenu();
        scanf("%d", &option);
        getchar();

        switch(option) {
            case 0:
                promptExit(pagesQueue);
                break;
            case 1: 
                promptAddPages(pagesQueue); 
                break;
            case 2:
                promptPrintPages(pagesQueue);
                break;
            case 3:
                promptClearPages(pagesQueue);
                break;
            case 4:
                promptFifoPageReplacement(pagesQueue, memoryQueue);
                break;
        }

    } while(option != 0);

    return 0;
}