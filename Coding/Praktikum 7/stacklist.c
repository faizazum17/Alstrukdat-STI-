// Nama : Faiza Aqiela Zuma
// NIM : 18220059
// Hari, Tanggal : Rabu, 9 November 2021
// Deskripsi : Implementasi dari stacklist.h

#include <stdio.h>
#include <stdlib.h>
#include "stacklist.h"

void Alokasi (address *P, infotype X){
    *P = (address) malloc (sizeof(ElmtStack));
    if (*P != Nil){
        Info(*P) = X;
        Next(*P) = Nil;
    }
}

void Dealokasi (address P){
    free(P);
}

boolean IsEmpty (Stack S){
    return (Top(S) == Nil);
}

void CreateEmpty (Stack * S){
    Top(*S) = Nil; 
}

void Push (Stack * S, infotype X){
    address P;
    Alokasi (&P, X);

    if (P != Nil){
        Next(P) = Top(*S);
        Top(*S) = P;
    }
}

void Pop (Stack * S, infotype * X){
    address P = Top(*S);

    if (Next(Top(*S)) == Nil){
        CreateEmpty(S);
    }
    else{
        Top(*S) = Next(Top(*S));
    }

    *X = Info(P);
    Dealokasi(P);
}