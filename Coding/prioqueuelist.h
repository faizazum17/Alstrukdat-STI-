/* File: prioqueuelist.h */
#define _PRIOQUEUELIST_H
#define _PRIOQUEUELIST_H
#include "boolean.h"
#include <stdlib.h>

#define Nil NULL
/* Deklarasi type elemen */
typedef int ElType;
/* Priority Queue dengan representasi berkait dengan pointer */
typedef struct tNode *address;
typedef struct tNode {
    ElType info;
    int prio;
    address next;
} Node;

/* Type PrioQueue dengan HEAD */
typedef struct {
address addrHead; /* alamat elemen pertama */
} PrioQueue;

/* Selektor */
#define NEXT(p) (p)->next
#define INFO(p) (p)->info
#define PRIO(p) (p)->prio

#define ADDR_HEAD(q) (q).addrHead
#define HEAD(q) (q).addrHead->info