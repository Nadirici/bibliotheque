#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef int BOOL;
#define TRUE  1
#define FALSE 0
#define TAILLE 100
#include "bibliotheque.h"

int main(){
    int b;
    Membre conect_user;
    conect_user = loginn();
    interface(conect_user);
    printf ("-----------------\n");
    scanf ("%d", &b);
    return 0;
}