// Nama : Faiza Aqiela Zuma
// NIM : 18220059
// Tanggal : Kamis, 30 September 2021
// Buat program yang menerima n pengguna yang online. tiap pengguna akan masuk pada waktu tertentu dalam 1 hari (dinyatakan dalam detik, misal pengguna masuk pada jam 1:05, maka waktu masuknya adalah 3900, yaitu 3600 (1 jam) + 300 (5 menit)). Setiap ada pengguna yang masuk, program harus mengoutputkan banyaknya pengguna yang online pada 5 menit terakhir

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int n;
infotype T;
Queue Q;

int main()
{
    scanf("%d",&n);
    CreateEmpty (&Q, 100);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &T);
        Add (&Q, T);
        if (NBElmt(Q) == 1)
        {
            printf("%d\n", 1);
        }
        else
        {
            if ((InfoTail(Q) - InfoHead(Q)) <= 300)
            {
                printf("%d\n", NBElmt(Q));
            }
            else
            {
                while (InfoTail(Q)-InfoHead(Q) > 300)
                {
                    Del(&Q, &T);
                }
                printf("%d\n", NBElmt(Q));
            }
        }
    }
    DeAlokasi(&Q);
    return 0;
}