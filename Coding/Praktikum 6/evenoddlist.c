// Nama : Faiza Aqiela Zuma
// NIM : 18220059
// Hari, Tanggal : Kamis, 4 November 2021
// Deskripsi : Buatlah program yang menerima sebuah list yang berisi beberapa buah bilangan. Lalu, pisahkan list tersebut menjadi list yang berisi bilangan genap dan list yang berisi bilangan ganjil. Kemudian, keluarkan list bilangan genap secara berurutan, dan keluarkan list bilangan ganjil secara berurutan terbalik.

#include <stdio.h>
#include <stdlib.h>
#include "listdp.h"
#include "listdp.c"

int main(){
    int n;
    List odd, even;
    CreateEmpty(&odd);
    CreateEmpty(&even);

    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        infotype a;
        scanf("%d", &a);
        if (a%2 == 0){
            InsVLast(&even, a);
        }else{
            InsVLast(&odd, a);
        }    
    }
    PrintForward(even);
    printf("\n");
    PrintBackward(odd);
    printf("\n");
}