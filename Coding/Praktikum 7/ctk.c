#include <stdio.h>
#include <stdlib.h>
#include "queuelist.h"

int main(){
    Queue Q;
    int n,x;
    CreateEmpty(&Q);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        Add(&Q,x);
        while(InfoTail(Q) - InfoHead(Q) > 300){
            Del(&Q,&x);
        }
        printf("%d\n",NbElmt(Q));
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "stacklist.h"

int main(){
    Stack S;
    infotype n,x,a,b;
    CreateEmpty(&S);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        if(x == 1){
            scanf("%d",&a);
            Push(&S,a);
        } else if(x == 2){
            Pop(&S,&a);
            Pop(&S,&b);
            a = a + b;
            Push(&S,a);
        } else if(x == 3){
            Pop(&S,&a);
            Pop(&S,&b);
            a = b - a;
            Push(&S,a);
        }
    }
    Pop(&S,&x);
    printf("%d\n",x);
    return 0;
}