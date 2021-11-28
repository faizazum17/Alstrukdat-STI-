// Nama : Faiza Aqiela Zuma
// NIM : 18220059
// Hari, Tanggal : Kamis, 11 November 2021
// Deskripsi : program yang menerima n pengguna yang online. tiap pengguna akan masuk pada waktu tertentu dalam 1 hari (dinyatakan dalam detik, misal pengguna masuk pada jam 1:05, maka waktu masuknya adalah 3900, yaitu 3600 (1 jam) + 300 (5 menit)). Setiap ada pengguna yang masuk, program harus mengoutputkan banyaknya pengguna yang online pada 5 menit terakhir.

#include <stdio.h>
#include <stdlib.h>
#include "queuelist.h"

int main(){
    int n, t;
    Queue Q;
    CreateEmpty(&Q);

    scanf("%d", &n);
    // input banyak operasi

    for (int i=0; i<n; i++){
        scanf("%d", &t);
        Add(&Q, t);
        while(InfoTail(Q) - InfoHead(Q) > 300){
            Del(&Q, &t);
        }
        printf("%d\n", NbElmt(Q));
    }
    return 0;
}