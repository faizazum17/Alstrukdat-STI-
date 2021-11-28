// Nama : Faiza Aqiela Zuma
// NIM : 18220059
// Tanggal : Kamis, 28 Oktober 2021
/* menerima beberapa instruksi atau query. Ada 3 jenis query yang program dapat terima:
Query pertama, memiliki format 1 x y , query ini akan memasukkan bilangan x sebanyak y kali ke depan list.
Query kedua, memiliki format 2 x y , query ini akan memasukkan bilangan x sebanyak y kali ke belakang list.
Query ketiga, memiliki format 3 z, query ini akan menghapus z bilangan dari depan dan belakang list, lalu output 
bilangan minimum dan maksimum yang dihapus tersebut. Pastikan untuk output bilangan minimum terlebih dahulu sebelum 
bilangan maksimum dalam baris yang sama. Apabila jumlah elemen pada list tidak cukup untuk dihapus, maka keluarkan -1 -1.*/

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

int main(){
    List L;
    CreateEmpty(&L);
    address p;
    int n, i, j, query, x, y, tempA, tempB, max, min;

    // Input Banyak query
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d",&query);
        // Untuk Query 1
        if(query == 1){
            scanf("%d %d",&x, &y);
            for(int j = 0;j < y;j++){
                InsVFirst(&L,x);
            }
        // Untuk Qury 2
        } else if(query == 2){
            scanf("%d %d",&x, &y);
            for(int j = 0;j < y;j++){
                InsVLast(&L,x);
            }
        // Untuk Query 3
        } else if(query == 3){
            scanf("%d",&x);
            if(NbElmt(L) >= x*2){
                min = Info(First(L));
                max = Info(First(L));
                for(int j = 0;j < x;j++){
                    DelVFirst(&L,&tempA);
                    DelVLast(&L,&tempB);
                    if(tempA <= tempB){
                        if(tempA < min){
                            min = tempA;
                        }
                        if(tempB > max){
                            max = tempB;
                        }
                    } else{
                        if(tempB < min){
                            min = tempB;
                        }
                        if(tempA > max){
                            max = tempB;
                        }
                    }
                }
                printf("%d %d\n", min, max);
            } else{
                printf("-1 -1\n");
            }
        }
    }
    return 0;
}

