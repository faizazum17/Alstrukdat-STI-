// Praktikum 1
// Nama        : Faiza Aqiela Zuma
// NIM         : 18220059
// Tanggal     : 09 September 2021
// Deksripsi   : Program yang menghitung jumlah dari semua faktor dari x

#include <stdio.h>
#include <math.h>

int main(){
    //Kamus
    int i, n, jmlfaktor;

    //ALGORITMA
    scanf("%d", &n);
    i = 1;
	jmlfaktor = 0;
	for(i = 1; i <= n; i++){
        if (n % i == 0) {
            jmlfaktor += i;
        }
		
	}
	printf("%d\n", jmlfaktor);

	return 0;
    
}

