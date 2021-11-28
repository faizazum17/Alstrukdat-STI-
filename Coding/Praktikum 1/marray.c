// Nama : Faiza Aqiela Zuma
// NIM : 18220059
// Date : 16/09/2021
// Deskripsi : Program yang menetukan array tersebut aritmatika atau geometri

#include <stdio.h>
#include "array.h"

int  main(){
    TabInt T;
    int n, i, x;
    ElType arr;
    float y;
    boolean aritmatika, geometri;

    aritmatika = 1;
    geometri = 1;

    // Input banyak array
    scanf("%d", &n);

    // Mengatur nilai efektif
    SetNeff(&T, n);
    for (IdxType i = 0; i < T.Neff; i++){
        scanf("%d", &arr);
        SetEl(&T, i, arr);
    }

    x = T.TI[1] - T.TI[0];
    y = T.TI[1] / T.TI[0];
    for (IdxType i = 1; i < T.Neff-1; i++){
        // Mengecek aritmatika
        if (T.TI[i+1] - T.TI[i] != x){
            aritmatika = 0;
        }
        // Mengecek geometri
        if (T.TI[i+1] / T.TI[i] != y){
            geometri = 0;
        }
    }

    //Output dari array
    if (geometri && aritmatika){
        printf("Keduanya\n");
    }
    else if (geometri && !aritmatika){
        printf("Geometri\n");
    }
    else if (aritmatika && !geometri){
        printf("Aritmatika\n");
    }
    else{
        printf("Bukan keduanya\n");
    }

    return 0;
}