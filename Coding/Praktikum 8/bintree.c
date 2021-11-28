// Nama : Faiza Aqiela Zuma
// NIM : 18220059
// Deskripsi : Implementasi bintree.h

#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

#define max(a, b) a>b?a:b

BinTree Tree (infotype Akar, BinTree L, BinTree R){
    BinTree P;
    P = (BinTree)malloc(sizeof(BinTree));
    if(P != Nil){
        Akar(P) = Akar;
        Left(P) = L;
        Right(P) = R;
  }
  return P;
}

void MakeTree (infotype Akar, BinTree L, BinTree R, BinTree *P){
    *P = (BinTree)malloc(sizeof(BinTree));
    if(P != Nil){
        Akar(*P) = Akar;
        Left(*P) = L;
        Right(*P) = R;
    }
}

addrNode AlokNode (infotype X){
    addrNode P;
    P = (addrNode) malloc(sizeof(Node));
    if (P != Nil) {
        Akar(P) = X;
        Left(P) = Nil;
        Right(P)= Nil;
    }
    return P;
}

void DealokNode (addrNode P){
    free(P);
}

boolean IsTreeEmpty (BinTree P){
    return P == Nil;
}

boolean IsTreeOneElmt (BinTree P){
    return !IsTreeEmpty(P) && (Left(P) == Nil) && (Right(P) == Nil);
}

boolean IsUnerLeft (BinTree P){
    if(IsTreeEmpty(P)) return false;
    else return Left(P) != Nil && Right(P) == Nil;
}

boolean IsUnerRight (BinTree P){
    if(IsTreeEmpty(P)) return false;
    else return Left(P) == Nil && Right(P) != Nil;
}

boolean IsBiner (BinTree P){
    if(IsTreeEmpty(P)) return false;
    else return Left(P) != Nil && Right(P) != Nil;
}

void PrintPreorder (BinTree P){
    if (IsTreeEmpty(P)) printf("()");
    else{
        printf("(");
        printf("%d", Akar(P));
        PrintPreorder(Left(P));
        PrintPreorder(Right(P));
        printf(")");
    }
}

void PrintInorder (BinTree P){
  printf("(");
  if(!IsTreeEmpty(P)){
    PrintInorder(Left(P));
    printf("%d", Akar(P));
    PrintInorder(Right(P));
  }
  printf(")");
}

void PrintPostorder (BinTree P){
  if (IsTreeEmpty(P)) printf("()");
  else{
    printf("(");
    PrintPostorder(Left(P));
    PrintPostorder(Right(P));
    printf("%d", Akar(P));
    printf(")");
  }
}

void PrintTree1(BinTree P, int h, int current_indent){
    if (!IsTreeEmpty(P)){
    printf("%*s%d\n", current_indent, "", Akar(P));
    PrintTree1(Left(P), h, current_indent + h);
    PrintTree1(Right(P), h, current_indent + h);
    }
}

void PrintTree (BinTree P, int h){
    PrintTree1(P,h, 0);
}

boolean SearchTree (BinTree P, infotype X){
    if(IsTreeEmpty(P)) return false;
    else{
        if (Akar(P) == X) return true;
        else{
            if (SearchTree(Left(P), X)) return true;
            else return (SearchTree(Right(P), X));
        }
    }
}

int NbElmt (BinTree P){
    if(IsTreeEmpty(P)) return 0;
    else return 1 + NbElmt(Left(P)) + NbElmt(Right(P));
}

int NbDaun (BinTree P){
  if(IsTreeEmpty(P)) return 0;
  if(IsTreeOneElmt(P)) return 1;
  else{
    if (IsUnerLeft(P)) return NbDaun(Left(P));
    else if (IsUnerRight(P)) return NbDaun(Right(P));
    else return NbDaun(Left(P)) + NbDaun(Right(P));
    }
}

boolean IsSkewLeft (BinTree P){
    if (IsTreeEmpty(P)){
        return true;
    }
    else if (IsTreeOneElmt(P)){
        return true;
    }
    else{
        return IsSkewLeft(Left(P)) && (Right(P) == Nil);
    }
}
boolean IsSkewRight (BinTree P){
    if (IsTreeEmpty(P)){
        return true;
    }
    else if (IsTreeOneElmt(P)){
        return true;
    }
    else{
        return IsSkewRight(Right(P)) && (Left(P) == Nil);
    }
}

int Level (BinTree P, infotype X){
    if (Akar(P) == X) return 1;
    else{
        if(SearchTree(Left(P), X)) return 1 + Level(Left(P), X);
        else if (SearchTree(Right(P), X)) return 1 + Level(Right(P), X);
    }
}

int Tinggi (BinTree P){
    if(IsTreeEmpty(P)) return 0;
    else{
      if (Tinggi(Left(P)) > Tinggi(Right(P))) return 1 + Tinggi(Left(P));
      else return 1 + Tinggi(Right(P));
    }
}


void AddDaunTerkiri (BinTree *P, infotype X){
  if(IsTreeEmpty(*P)) *P = Tree(X, Nil, Nil);
  else AddDaunTerkiri(&Left(*P), X);
}

void AddDaun (BinTree *P, infotype X, infotype Y, boolean Kiri){
  if(Akar(*P)==X && IsTreeOneElmt(*P)){
    if(Kiri) Left(*P) = Tree(Y,Nil,Nil);
    else Right(*P) = Tree(Y,Nil,Nil);
  } else {
    if(SearchTree(Left(*P),X)) AddDaun(&Left(*P),X,Y,Kiri);
    else AddDaun(&Right(*P),X,Y,Kiri);
  }
}

void DelDaunTerkiri (BinTree *P, infotype *X){
  if(IsTreeOneElmt(*P)){
    *X = Akar(*P);
    addrNode del = *P;
    *P = Nil;
    DealokNode(del); 
  } else {
    if(Left(*P)!=Nil){
      DelDaunTerkiri(&Left(*P), X);
    } else {
      DelDaunTerkiri(&Right(*P), X);
    }
  }
}

void DelDaun (BinTree *P, infotype X){
    if (!IsTreeEmpty(*P)){
        if (IsTreeOneElmt(*P) && Akar(*P) == X){
            (*P) = Nil;
            DealokNode(*P);
        }
        else{
            DelDaun(&Left(*P), X);
            DelDaun(&Right(*P), X);
        }
    }
}

