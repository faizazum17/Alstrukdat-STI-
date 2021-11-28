// Nama : Faiza Aqiela Zuma
// NIM : 18220059
// Tanggal : Kamis, 30 September 2021
// Implementasi listlinier.h

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

boolean IsEmpty (List L){
// Mengirim true jika list kosong
    return First(L) == Nil;
}

void CreateEmpty (List *L){
// I.S. sembarang
// F.S. Terbentuk list kosong 
    First(*L) = Nil;
}

address Alokasi (infotype X){
    address p;
    p = (address) malloc (sizeof(ElmtList));
    if (p != Nil){
        Info(p) = X;
        Next(p) = Nil;
    }
    return p;
}

void Dealokasi (address *P){
// I.S. P terdefinisi
// F.S. P dikembalikan ke sistem
// Melakukan dealokasi/pengembalian address P
    free(*P);
}

address Search (List L, infotype X){
    if (IsEmpty(L)) return Nil;

    address now = First(L);
    while(now != Nil && Info(now)!=X){
        now = Next(now);
    }
    return now;
}

void InsVFirst (List *L, infotype X){
// I.S. L mungkin kosong 
// F.S. Melakukan alokasi sebuah elemen dan 
// menambahkan elemen pertama dengan nilai X jika alokasi berhasil 
    address newP = Alokasi(X);
    if (newP != Nil){
        Next(newP) = First(*L);
        First(*L) = newP;
    }
}

void InsVLast (List *L, infotype X){
// I.S. L mungkin kosong 
// F.S. Melakukan alokasi sebuah elemen dan 
// menambahkan elemen list di akhir: elemen terakhir yang baru 
// bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. 
    address newlast = Alokasi(X);
    if (newlast == Nil) return;

    if (IsEmpty(*L)){
        InsVFirst(L, X);
    } else {
        address now = First(*L);
        while (Next(now) != Nil){
            now = Next(now);
        }
        Next(now) = newlast;
        Next(Next(now)) = Nil;
    }
}

void DelVFirst (List *L, infotype *X){
// I.S. List L tidak kosong
// F.S. Elemen pertama list dihapus: nilai info disimpan pada X
// dan alamat elemen pertama di-dealokasi
    address deletedP = First(*L);
    *X = Info(deletedP);
    First(*L) = Next(deletedP);

    Dealokasi(&deletedP);
}

void DelVLast (List *L, infotype *X){
// I.S. list tidak kosong
// F.S. Elemen terakhir list dihapus: nilai info disimpan pada X 
// dan alamat elemen terakhir di-dealokasi */    
    address now = First(*L);
    if(Next(now) != Nil){
        while(Next(Next(now)) != Nil){
            now = Next(now);
        }
        *X = Info(Next(now));
        Dealokasi(&Next(now));
        Next(now) = Nil;
    }else{
        DelVFirst(L, X);
    }
}

void InsertFirst (List *L, address P){
// I.S. Sembarang, P sudah dialokasi  
// F.S. Menambahkan elemen ber-address P sebagai elemen pertama 
    address first = First(*L);
    if (P != Nil){
        Next(P) = first;
        First(*L) = P;
    }
}

void InsertLast (List *L, address P){
// I.S. Sembarang, P sudah dialokasi  
// F.S. P ditambahkan sebagai elemen terakhir yang baru
    if (P == Nil) return;

    if (IsEmpty(*L)){
        First(*L) = P;
    } else {
        address now = First(*L);
        while (Next(now) != Nil){
            now = Next(now);
        }
        Next(P) = Nil;
        Next(now) = P;
    }
}

void DelLast (List *L, address *P){
    address now = First(*L);
    if(Next(now) == Nil){
        DelFirst(L, P);
    }else{
        while(Next(Next(now)) != Nil){
            now = Next(now);
        }
        DelAfter(L, P, now);
    }
}

void DelP (List *L, infotype X){
// I.S. List tidak kosong 
// F.S. P adalah alamat elemen terakhir list sebelum penghapusan 
// Elemen list berkurang satu (mungkin menjadi kosong) 
// Last element baru adalah predesesor elemen terakhir yg lama,
/* jika ada */
    if(!IsEmpty(*L)){
        address now = First(*L);
        address dummy;
        if(Info(now) == X){
            DelFirst(L, &dummy);
        }else{
            while(Next(now) != Nil && Info(Next(now)) != X){
                now = Next(now);
            }
            if(Next(now) != Nil){
                DelAfter(L, &dummy, now);
            }
        }
    }
}

void DelFirst (List *L, address *P){
// I.S. List tidak kosong
// F.S. P adalah alamat elemen pertama list sebelum penghapusan
// Elemen list berkurang satu (mungkin menjadi kosong) 
// First element yg baru adalah suksesor elemen pertama yang lama
    address deletedP = First(*L);
    *P = deletedP;
    First(*L) = Next(deletedP);
}

void DelAfter (List *L, address *Pdel, address Prec){
// I.S. List tidak kosong. Prec adalah anggota list 
// F.S. Menghapus Next(Prec): 
//      Pdel adalah alamat elemen list yang dihapus  

    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
}

void PrintInfo (List L){
// I.S. List mungkin kosong
// F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] 
    printf("[");
    if (!IsEmpty(L)){
        address now = First(L);
        while (now != Nil) {
            printf("%d", Info(now));
            now = Next(now);

            if (now != Nil)
                printf(",");
        }
    }
    printf("]");
}

int NbElmt (List L){
// Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong 
    int n = 0;
    if (!IsEmpty(L)){
        address now = First(L);
        while (now != Nil){
            n++;
            now = Next(now);
        }
    }
    return n;
}

infotype Max (List L){
// Mengirimkan nilai Info(P) yang maksimum */
    address now = First(L);
    infotype max = Info(now);
    while (Next(now) != Nil){
        now = Next(now);
        if (Info(now) > max){
            max = Info(now);
        }
    }
    return max;
}

void Konkat1 (List *L1, List *L2, List *L3){
// I.S. L1 dan L2 sembarang
// F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2
    CreateEmpty(L3);
    First(*L3) = First(*L1);
    First(*L1) = Nil;
    if (IsEmpty(*L3)){
        First(*L3) = First(*L2);
    } else {
        address now = First(*L3);
        while (Next(now) != Nil){
            now = Next(now);
        }
        Next(now) = First(*L2);
    }
    First(*L2) = Nil;
}

void InsertAfter (List *L, address P, address Prec){
// I.S. Prec pastilah elemen list dan bukan elemen terakhir, 
// P sudah dialokasi  
// F.S. Insert P sebagai elemen sesudah elemen beralamat Prec 
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

address AdrMax (List L){
    return Search(L, Max(L));
}

address AdrMin (List L){
    return Search(L, Min(L));
}

infotype Min (List L){
    address p = First(L);
    infotype min = Info(p);
    while (Next(p) != Nil){
        p = Next(p);
        if (Info(p) < min){
            min = Info(p);
        }
    }
    return min;
}

float Average (List L){
	if (IsEmpty(L)){
		return 0;
	} else {
		address P = First(L);
		float total = Info(P);
		float count = 1;
		while (Next(P) != Nil){
			P = Next(P);
			total = total + Info(P);
			count++;
		}
		return (total/count);
	} 
}

void InversList (List *L){
	if (!IsEmpty(*L)){
		address P = First(*L);
		while (Next(P) != Nil){
			P = Next(P);
		}
		address last = P;
		address Prec;
		while (P != First(*L)){
			Prec = First(*L);
			while (Next(Prec) != P){
				Prec = Next(Prec);
			}
			Next(P) = Prec;
			P = Next(P);
		}
		Next(P) = Nil;
		First(*L) = last;
	}
}