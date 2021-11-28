// Nama : Faiza Aqiela Zuma
// NIM : 18220059
// Date : 16/09/2021
// Deskripsi : Program yang menetukan apakah ada perulangan

#include <stdio.h>
#include "array.h"

int  main(){
    TabInt T;
    int n, i, j;
    ElType arr;
    boolean aritmatika, geometri;

    // Input banyak array
    scanf("%d", &n);

    // Mengatur nilai efektif
    SetNeff(&T, n);
    for (IdxType i = 0; i < T.Neff; i++){
        scanf("%d", &arr);
        SetEl(&T, i, arr);
    }

    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(arr[i] == arr[j])
            {
                printf(" %d ", arr[i]);
                break;
            }
        }
    }

    return 0;
}

