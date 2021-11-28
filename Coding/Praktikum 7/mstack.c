// Nama : Faiza Aqiela Zuma
// NIM : 18220059
// Hari, Tanggal : Kamis, 11 November 2021
// Deskripsi : Buatlah program mstack.c yang dapat menyimulasikan notasi postfix dengan ketentuan

#include <stdio.h>
#include <stdlib.h>
#include "stacklist.h"

int main(){
    infotype n, query, x, y;
    Stack S;
    CreateEmpty(&S); 

    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &query);
        if(query == 1){
            scanf("%d",&x);
            Push(&S,x);
        } else if(query == 2){
            Pop(&S,&x);
            Pop(&S,&y);
            x = x + y;
            Push(&S,x);
        } else if(query == 3){
            Pop(&S,&x);
            Pop(&S,&y);
            x = y - x;
            Push(&S,x);
        }
    }
    printf("%d\n", InfoTop(S));
    return 0;
}