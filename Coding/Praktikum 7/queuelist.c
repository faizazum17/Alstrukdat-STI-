// Nama : Faiza Aqiela Zuma
// NIM : 18220059
// Hari, Tanggal : Rabu, 9 November 2021
// Deskripsi : Implementasi dari queuelist.h

#include <stdio.h>
#include <stdlib.h>
#include "queuelist.h"

void Alokasi (address *P, infotype X){
    *P = (address) malloc(sizeof(ElmtQueue));
    if (*P != Nil){
        Info(*P) = X;
        Next(*P) = Nil;
    }
}

void Dealokasi (address  P){
    free(P);
}

boolean IsEmpty (Queue Q){
    return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}

int NbElmt(Queue Q){
    int counter = 0;
    address P = Head(Q);

    while (P != Nil){
        P = Next(P);
        counter ++;
    }
    return counter;
}

void CreateEmpty(Queue * Q){
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}

void Add (Queue * Q, infotype X){
    address P;
    Alokasi(&P, X);

    if (P != Nil){
        if ( IsEmpty(*Q)){
            Head(*Q) = P;
            Tail(*Q) = P;
        }
        else{
            Next(Tail(*Q)) = P;
            Tail(*Q) = P;
        }
    }
}

void Del(Queue * Q, infotype * X){
    address P = Head(*Q);
    if(Next(Head(*Q)) == Nil){
        CreateEmpty(Q);
    }
    else{
        Head(*Q) = Next(Head(*Q));
    }
    *X = Info(P);
    Dealokasi(P);
}