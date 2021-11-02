#include <stdlib.h>
#include <stdio.h>
#include "prioqueuelist.h"
#include "prioqueuelistctk.c"

void PrintQueue(PrioQueue Q){
    address P;
    P = ADDR_HEAD(Q);
    while (P != Nil){
        printf("Info list adalah %d dengan prioritas %d\n",INFO(P), PRIO(P));
        P = NEXT(P);
    }
}

int main(){
    PrioQueue q;
    int x, pr, add = 1,print,del;

    CreateQueue(&q);
    while (add != 0){
        scanf("%d %d", &x, &pr);
        enqueue(&q, x, pr);
        printf("Ingin menghapus elemen (y=1/t=0): ");
        scanf("%d", &del);
        if (del == 1) dequeue(&q, &x, &pr);
        printf("Print anggota Queue? (y=1/t=0): ");
        scanf("%d", &print);
        if (print == 1)PrintQueue(q);
        printf("Ingin menambahkan elemen? (y=1/t=0): ");
        scanf("%d", &add);
    }
    return 0;
}