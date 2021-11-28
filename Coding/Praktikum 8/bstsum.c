// Nama : Faiza Aqiela Zuma
// NIM : 18220059
// Deskripsi :Baris pertama masukan berupa bilangan bulat positif N (1 <= N <= 20) yang menunjukkan banyaknya node yang akan dimasukkan ke dalam BST.
// N Baris selanjutnya berisi 1 buah bilangan yang akan menjadi node dari BST. Setiap bilangan dijamin unik.

#include <stdio.h>
#include "bintree.h"

void AddBST (BinTree *P, infotype elmt){
    if(IsTreeEmpty(*P)) *P = Tree(elmt, Nil, Nil);
    else if (IsTreeOneElmt(*P)){
        if (elmt <= Akar(*P)){
            Left(*P) = Tree(elmt, Nil, Nil);
        }
        else{
            Right(*P) = Tree(elmt,Nil, Nil);
        } 
    }else{
        if (elmt <= Akar(*P)){
            AddBST(&Left(*P), elmt);
        }
        else{
            AddBST(&Right(*P), elmt);
        }
    }
}

int getSum(BinTree T){
    if(IsTreeEmpty(T)) {
        return 0;
    }
    else{
        return Akar(T) + getSum(Left(T)) + getSum(Right(T));
    }
}

BinTree SearchAddrTree(BinTree T, infotype X){
    if(IsTreeEmpty(T)){
        return Nil;
    }
    else{
        if (Akar(T) == X){
            return T;
        }
        else{
            if (SearchAddrTree(Left(T), X)){
                return (SearchAddrTree(Left(T), X));
            }
            else{
                return (SearchAddrTree(Right(T), X));
            }
        }
    }
}

int main(){
    int root, n, searchAkar;
    BinTree BST, searchBST;

    BST = Nil;
    scanf("%d",&n);
    for (int i=0; i < n; i++){
        scanf("%d",&root);
        AddBST(&BST, root);
    }
    
    scanf("%d",&searchAkar);
    searchBST = SearchAddrTree(BST, searchAkar);
    printf("%d\n", getSum(searchBST));
}