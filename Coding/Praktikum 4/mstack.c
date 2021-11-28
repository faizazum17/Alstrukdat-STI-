// Nama : Faiza Aqiela Zuma
// NIM : 18220059
//Buat program yang dapat menerima 2 set operasi, dan membandingkan apakah hasil dari 2 set operasi tersebut sama

#include <stdio.h>
#include "stack.h"

int n, i, T;
Stack S1, S2;
boolean ans;

int main(){
    //Membuat empty stack
    CreateEmpty(&S1);
    CreateEmpty(&S2);
    //Mengatur stack 1
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &T);
        if(T == -1)
        {
            if(!IsEmpty(S1))
            {
                Pop(&S1, &T);
            }
        }
        else 
        {
            Push(&S1, T);
        }

    }

    //Mengatur Stack 2
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &T);
        if(T == -1)
        {
            if(!IsEmpty(S2))
            {
                Pop(&S2, &T);
            }
        }
        else 
        {
            Push(&S2, T);
        }

    }

    ans = false;
    if(Top(S1) != Top(S2))
    {
        printf("BEDA\n");
    }
    else
    {
        i = Top(S1);
        while(!ans && i >= 0)
        {
            if(InfoTop(S1) != InfoTop(S2))
            {
                printf("BEDA\n");
                ans = true;
            }
            i--;
        }
        if(!ans)
        {
            printf("SAMA\n");
        }
    }
    return 0;
}