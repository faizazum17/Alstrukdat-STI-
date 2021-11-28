// Nama : Faiza Aqiela Zuma
// NIM : 18220059
// Deskripsi : diinput sebuah kata kemudian output sebuah kata yg telah di tranvesered

#include "mesin_kata.h"
#include <stdio.h>

void printKata(Kata kata);
int main() 
{
    int x = 0;
    scanf("%d",&x);
    STARTKATA();
    Kata CC = CKata;
    int i,j;
    char tStart,temp,tEnd,store;
    for (i=0; i<x+1; i++) 
    {
        for (j=1; j<=CC.Length; j++)
        {
            if (j == 1) 
            {
                tStart = CC.TabKata[1]; tEnd = CC.TabKata[CC.Length];
                CC.TabKata[1] = CC.TabKata[2];
                CC.TabKata[CC.Length] = tStart;
            } 
            
            else if(j == CC.Length-1)
            {
                CC.TabKata[CC.Length-1] = tEnd;
                break;
            } 
            
            else 
            {
                CC.TabKata[j] = CC.TabKata[j+1];
            }
        }
    }
    printKata(CC);
    printf("\n");
    return 0;
}

void printKata(Kata kata) 
{
  for(int i = 0; i <= kata.Length; i++)
  {
    if (kata.TabKata[i] != '\n' && kata.TabKata[i] != BLANK) 
    {
       printf("%c", kata.TabKata[i]);
    }
  }
  printf("\n");
}



