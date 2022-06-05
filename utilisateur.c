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

//works
int verifligne (FILE * fp){
    char b[TAILLE];
    int longueur = 0;
    while (fgets (b, 1000, fp) != NULL){
        
        longueur = longueur + 1;
    }
    
    return longueur;
}

//works
Membre create (){
    Membre a;
    printf ("quel est ton prenom?\n");
    scanf ("%s", a.prenom);
    printf ("quel est ton nom?\n");
    scanf ("%s", a.nom);
    printf ("quel sera ton mdp?\n");
    scanf ("%s", a.mdp);
    do{
        printf("Tapez 1 si vous etes un etudiant ou 2 si vous etes un professeur\n");
        a.status = lis_entier(1, 2);
    }while (a.status != 1 && a.status != 2);
    puts("ee");
    return a;

}



Membre verif2 (char testprenom[TAILLE], char testnom[TAILLE], char testmdp[TAILLE]){
    FILE *fp = fopen ("user.txt", "r+");
    char linebreak[100];
    char tempFstName[100];
    char tempSndName[100];
    char tempMdp[100];
    int longueur;
    int ident , max_l ;
    Livre l1 , l2 , l3 , l4 , l5 ;
    int status ;
    int nmb_livre ;
    Membre conect;
    int count1 = 0;
    int count2 = 0;

    if (fp == NULL){
        printf ("\nVeuiller d'abord creer un identifiant\n");
    }
    longueur = verifligne (fp);
    rewind (fp);
    for (int i = 0; i < longueur-1; i++){
        fgets (linebreak, 99, fp);
        fscanf (fp, "%s", tempFstName);
        fscanf (fp, "%s", tempSndName);
        fscanf (fp, "%s", tempMdp);
        fscanf (fp, "%d", &ident);
        fscanf (fp, "%d", &status);
        fscanf (fp, "%d", &nmb_livre);
        fscanf (fp, "%d", &max_l);
        fscanf (fp, "%s", &l1.num);
        fscanf(fp, "%d", &l2.num);
        fscanf(fp, "%d", &l3.num);
        fscanf(fp, "%d", &l4.num);
        fscanf(fp, "%d", &l5.num);
        if (strcmp (tempFstName, testprenom) != 0 || strcmp (tempSndName, testnom) != 0){
            count1 = count1 + 1;	
        }
        else{
            if (strcmp (tempMdp, testmdp) != 0){
                count2 = count2 + 1;	
            }
            else{
               *conect.prenom = tempFstName ;
               *conect.nom = tempSndName ;
               *conect.mdp = tempMdp ;
               
               conect.identifiant = ident ;
               conect.status = status ;
               conect.nmb_livre = nmb_livre ;
               conect.max_l = max_l ;
               conect.l1.num = l1.num ;
               conect.l2.num = l2.num ;
               conect.l3.num = l3.num ;
               conect.l4.num = l4.num ;
               conect.l5.num = l5.num ;
            }
        }
    }
    if (count1 != longueur - 2 || count2 != 0){
        printf ("\nl'identifiant ou le mot de passe est incorrect, veuillez reesayer\n");
    }
    else if(count1 == longueur - 2 && count2 == 0){
        printf(" Bonjour ,vous vous etes connecter a la bibliotheque!\n");
        
    }
    return conect ;
    fclose (fp);
}



void registr (char prenom[TAILLE], char nom[TAILLE], char *mdp, int status){

    FILE *fp = fopen ("user.txt", "a+");
    if (fp == NULL){
        printf ("erreur fopen");
        exit (1);
    }
    fputs ("\n", fp);
    fprintf (fp, "%s", prenom);
    fprintf (fp, "%c", ' ');
    fprintf (fp, "%s", nom);
    fprintf (fp, "%c", ' ');
    fprintf (fp, "%s", mdp);
    fprintf (fp, "%c", ' ');
    srand(time(NULL));
    fprintf(fp, "%c_%c_%c ",rand()%26+'A',rand()%26+'A',rand()%26+'A');
    fprintf (fp, "%c", ' ');
    if (status == 1){
        fprintf (fp, "%d",status);
    }
    else{
        fprintf (fp, "%d",status);
    }
    fprintf (fp, "%c", ' ');
    if (status == 1){
        fprintf (fp,"%d", 3);
    }
    else{
        fprintf (fp,"%d", 5);
    }
    fprintf (fp, "%c", ' ');
    fprintf (fp, "%d", 0);
    for (int i = 0; i < 5; i++){
        fprintf (fp, "%c", ' ');
        fprintf (fp, "0");
    }
    fclose (fp);
}

    //fonction qui permet la connexion de l'utilisateur à la bibliothèque
Membre loginn(){
    int connect = 2;
    Membre nouveau;
    Membre ident;
    char tprenom[TAILLE];
    char tnom[TAILLE];
    char tmdp[TAILLE];
    do{
        printf("\n-------------------------------------------------------------\n");
        printf("----Bienvenue a  la bibliotheque universitaire de CY TECH----\n");
        printf("	                    0: Insciption                          \n");
        printf("	                    1: Connexion                           \n");
        connect =lis_entier(0,1);
    }while (connect != 0 && connect != 1);
    if (connect == 0){
        nouveau = create ();
        registr (nouveau.prenom, nouveau.nom, nouveau.mdp, nouveau.status);
        printf ("-----Connectez vous-----\n");
        printf ("Entrez votre prenom\n");
        scanf ("%s", tprenom);
        printf ("Entrez votre nom\n");
        scanf ("%s", tnom);
        printf ("Entrez votre mot de passe\n");
        scanf ("%s", tmdp);
        ident =  verif2 (tprenom, tnom, tmdp);
        return ident ;
    }
    else{
        printf ("Entrez votre prenom\n");
        scanf ("%s", tprenom);
        printf ("Entrez votre nom\n");
        scanf ("%s", tnom);
        printf ("Entrez votre mot de passe\n");
        scanf ("%s", tmdp);
        ident = verif2 (tprenom, tnom, tmdp) ;
        return ident ;
        
    }
}


// fonction qui oblige l'utilisateur a ecrire un int entre une borne min et max
int lis_entier(int Min, int Max) {
    char  string[255];
    int   entier = 0;
    BOOL  OK;
    int   i;
    do {
        OK = FALSE;
        scanf("%s", string);
        /* On déchiffre l'entier. */
        for (i = 0; i < strlen(string); i++) {
            if (!isdigit(string[i])) {
                /* Si un des caractères lus n'est pas un chiffre, on arrête de déchiffrer. */
                OK = TRUE;
                break;
            }
            entier = 10 * entier + (string[i] - '0');
        }
        /* Si on a bien lu un entier, on teste s'il est dans les bornes. */
        if (OK  &&  (entier < Min  ||  entier > Max)) {
            OK = TRUE;
        }
        /* On affiche un message d'erreur si la saisie est incorrecte. */
        if (OK) {
            printf("Saisie incorrecte. Veuillez entrer soit %d soit %d.\n",
                   Min, Max);
        }
    } while (OK);
    return entier;
}