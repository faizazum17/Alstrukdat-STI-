#include <stdio.h>
#include <math.h>
#include "point.h"

POINT MakePOINT (float X, float Y) {
    POINT p;
    Absis(p) = X;
    Ordinat(p) = Y;
    return p;
}

void BacaPOINT (POINT * P) {
    float absis;
    float ordinat;
    scanf("%f %f", &absis, &ordinat);
    *P = MakePOINT(absis, ordinat);
}

void TulisPOINT(POINT P){
    printf("(%2.f, %2.f)", Absis(P), Ordinat(P));
}

boolean EQ (POINT P1, POINT P2){
    return Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2);
}

boolean NEQ (POINT P1, POINT P2) {
    return !EQ(P1, P2);
}
