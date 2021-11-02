//Nama : Faiza Aqiela Zuma
//NIM :  18220059

#include <stdio.h>
#include <stdlib.h>
#include "prioqueuelist.h"

/* Prototype manajemen memori */
address newNode(ElType x, int pr){
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x dan prio = pr,
atau NIL jika alokasi gagal */
    address P;

    P = (address) malloc (sizeof(Node));
    if (P != Nil)
    {
        INFO(P) = x;
        PRIO(P) = pr;
        NEXT(P) = Nil;
        return P;
    }
    else return Nil;
}

void delNode(address P){
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
    free(P);
}

boolean isEmpty(PrioQueue q){
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NIL and ADDR_TAIL(q)=NIL */
    return ADDR_HEAD(q) == Nil;
}

int length(PrioQueue q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */
    int lenght;
    address P;

    if (isEmpty(q)) return 0;
    else{
        lenght = 0;
        P = ADDR_HEAD(q);
        while (P != Nil){
            lenght++;
            P = NEXT(P);
        }
        return lenght;
    }
}   

/*** Kreator ***/
void CreateQueue(PrioQueue *q){
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */
    ADDR_HEAD(*q) == Nil;
}

/*** Primitif Enqueue/Dequeue ***/
void enqueue(PrioQueue *q, ElType x, int pr);
/* Proses: Mengalokasi x dengan prio pr dan menambahkan x pada q
jika alokasi berhasil; jika alokasi gagal q tetap */

/* I.S. q mungkin kosong */
/* F.S. x menjadi elemen q sesuai dengan urutan prioritas */
void dequeue(PrioQueue *q, ElType *x, int *pr);
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */