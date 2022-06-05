#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
typedef int BOOL;
#define TRUE  1
#define FALSE 0
#define TAILLE 100

typedef struct Livre{
    char titre[TAILLE];
    char auteur[TAILLE];
    char type[TAILLE];
    int num;
    int dispo;
} Livre;


typedef struct{
    char prenom[TAILLE];
    char nom[TAILLE];
    char mdp[TAILLE];
    int identifiant;
    int status;
    int nmb_livre;
    int max_l ;
    Livre l1, l2, l3, l4, l5 ;
} Membre;

//fonction qui propose les livres disponible

int livre_dispo(Membre user){
    char ref_l ;
    if (user.nmb_livre == user.max_l){
        printf("Vous avez emprunter le nombre maximum de livre") ;
        return 0 ;
    }
    FILE *fp = fopen ("livre.txt", "a+");
    if (fp == NULL){
        printf ("erreur fopen");
        exit (1);
    }
    char linebreak[TAILLE];
    char title[TAILLE];
    char autor[TAILLE];
    char categorie[TAILLE];
    
    int ref;
    int longueur = verifligne (fp);
    rewind (fp);
    puts("Voici la liste des livres disponibles");
    for (int i = 0; i < longueur - 1; i++){
        fgets (linebreak, 99, fp);
        fscanf (fp, "%s", &title);
        fscanf (fp, "%s", &autor);
        fscanf (fp, "%s", &categorie);
        fscanf (fp, "%d", &ref) ;
        printf ("%s ref : %d \n", title , ref) ;
    }
    printf("Entrez la réference du livre souhaiter ? \n") ;
    scanf("%d ",&ref_l) ;
    puts("Livre emprunter") ;
    fclose (fp) ;
    fp = fopen("livre.txt", "r+") ;
    rewind (fp);
    if (ref_l == 1)
        fseek(fp, 48, SEEK_SET);
    if (ref_l == 2)
        fseek(fp, 94, SEEK_SET);
    if (ref_l == 3)
        fseek(fp, 143, SEEK_SET);
    if (ref_l == 4)
        fseek(fp, 172, SEEK_SET);
    if (ref_l == 5)
        fseek(fp, 211, SEEK_SET);
    if (ref_l == 6)
        fseek(fp, 236, SEEK_SET);
    if (ref_l == 7)
        fseek(fp, 264, SEEK_SET);
    fprintf (fp, "%d", 0);
    fclose (fp);
    return 0 ;
}

void rendre_l(Membre user){
    if (user.nmb_livre == 0){
        puts("Vous n'avez pas de livre à rendre");
        return 0 ;
    }
    puts("Vous empruntez actuelment : ");
    printf("\n1.%c \n2.%c \n3.%c \n4.%c \n5.%c \n", user.l1 , user.l2 , user.l3 , user.l4 , user.l5) ;
    puts("Quelle livre souhaiter vous rendre ?");
    
}

void interface(Membre user){
    int c ;
    printf("\nQue souhaitez vous faire ? \n") ;
    printf("1.Emprunter un livre \n2.Rendre un livre \n3.Se deconnecter \n") ;
    scanf("%d", &c) ;
    if (c == 1){
        livre_dispo(user);
    }
    if (c == 2){
        rendre_l(user);
    }
    if (c == 3){
        loginn() ;
    }
}