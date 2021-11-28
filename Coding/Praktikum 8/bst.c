// Nama : Faiza Aqiela Zuma
// NIM : 18220059
// Deskripsi : Baris pertama masukan berupa bilangan bulat positif N yang menunjukkan banyaknya node yang akan dimasukkan ke dalam BST. Baris selanjutnya berisi N bilangan yang akan menjadi node dari BST. 
// Keluaran berupa hasil print preorder dari BST yang dihasilkan. Kemudian dilanjutkan dengan tinggi dari BST tersebut.

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

int main(){
    int root,n;
    BinTree BST;

    BST = Nil;
    scanf("%d",&n);
    for (int i=0; i < n; i++){
        scanf("%d",&root);
        AddBST(&BST, root);
    }
    PrintPreorder(BST);
    printf("\n");
    printf("%d\n", Tinggi(BST));
    return 0;
}