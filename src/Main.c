#include <stdio.h>
#include <stdlib.h>

#include "../include/Queue.h"

int fifoPageReplacement(Queue* pagesQueue, Queue* memoryQueue, int frames) {
    QueueClear(memoryQueue);
    int pageFaults = 0;

    printf(" \t[]\n");

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

        printf("%d\t", number); QueuePrint(memoryQueue);

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

void promptAddPages(Queue* pagesQueue) {
    clearScreen();

    int number;
    printf("\n==================================================\n");
    printf("        ** Adicionar Sequência de Páginas **     \n");
    printf("==================================================\n");
    printf("Digite os números separados apenas por Vírgula e Espaço.\n");
    printf("Pressione Enter quando terminar:\n");

    while(1) {
        scanf("%d", &number);

        QueueEnqueue(pagesQueue, number);

        if(getchar() == '\n')
            break;
    }

    printf("\nSequência de páginas adicionada com sucesso.\n");
    printf("\nPressione Enter para voltar ao menu...\n");
    getchar();
}

void promptPrintPages(Queue* pagesQueue) {
    clearScreen();
    printf("\n===============================================\n");
    printf("      ** Imprimir Sequência de Páginas **      \n");
    printf("===============================================\n");

    QueuePrint(pagesQueue);

    printf("\nPressione Enter para voltar ao menu...\n");
    getchar();
}

void promptExit(Queue* pagesQueue, Queue* memoryQueue) {
    clearScreen();
    printf("\n===============================================\n");
    printf("            ** Saindo do Aplicativo **         \n");
    printf("===============================================\n");

    QueueDestroy(pagesQueue);
    QueueDestroy(memoryQueue);
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

        printf("Página\tMemória\n");
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
        QueueClear(pagesQueue);
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
                promptExit(pagesQueue, memoryQueue);
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
