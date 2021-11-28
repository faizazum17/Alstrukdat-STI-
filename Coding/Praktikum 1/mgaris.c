// Praktikum 1
// Nama        : Faiza Aqiela Zuma
// NIM         : 18220059
// Tanggal     : 09 September 2021
// Deksripsi   : garis sejajar dan garis tegak lurus

#include <stdio.h>
#include <math.h>
#include "garis.h"

int main(){
    int n, i, sejajar, tegakLurus;
    GARIS L1, L2;
    sejajar = 0;
    tegakLurus = 0;

    BacaGARIS(&L1);

    scanf("%d", &n);
    for (i=1; i <= n; i++){
        BacaGARIS(&L2);
        if (IsSejajar(L1, L2)){
            sejajar += 1;
        }
        if (IsTegakLurus(L1,L2)){
            tegakLurus += 1;
        }
    }

    printf("Sejajar: %d\n", sejajar);
    printf("Tegak lurus: %d\n", tegakLurus);

    return 0;
}
