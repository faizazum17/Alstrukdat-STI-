// Nama : Faiza Aqiela Zuma
// NIM : 18220059
// Deskripsi : insert bahasa G pada kata

#include <stdio.h>
#include "mesin_kata.h"

void insertG(Kata kata);
boolean isVocal(char x);
void hasilG();

int main(){
  STARTKATA();
  while (!EndKata){
    insertG(CKata);
    hasilG();
  }
  return 0;
}

boolean isVocal(char x){
  return ((x == 'a') || (x == 'i') || (x == 'u') || (x == 'e') || (x = 'o'));
}

void insertG(Kata kata){
  for (int i = 1; i <= kata.Length; i++){
    printf("%c", kata.TabKata[i]);
    if (isVocal(kata.TabKata[i])){
      printf("g%c", kata.TabKata[i]);
    }
  }
}

void hasilG(){
  IgnoreBlank();
  if (CC == MARK){
    EndKata = TRUE;
    printf("\n");
  }
    else{
      SalinKata();
      printf(" ");
    }
}
