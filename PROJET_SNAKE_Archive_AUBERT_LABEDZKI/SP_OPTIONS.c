#include <stdio.h>
#include <time.h>
#include "mesTypes.h"
#include "myLib.h"
#include "SP_GESTION_JEU.h"

// =============================================================================
// Nom : SP_AFFICHE_PARAMETRES
// Sémantique : Affiche le sous menu des paramétrès
// Paramètres:       aucune
// Pré-conditions :  aucune
// Post-conditions : aucune
// ============================================================================
// Test
// ============================================================================
// FONCTION SP_AFFICHE_PARAMETRES ()

void AFFICHER_PARAMETRES(TYPE_PARAM_JEU* PT_ParamJeu)
{
    cls();
    int quitter = 0;
    int pos_gauche = 47;
    int pos_droite = 71;
    int pos_y      = 14;

    do {
    int direction = SP_Gestion_Clavier();
    msleep(50);

    if (pos_y >= 18) {pos_y = 14;}
    if (pos_y <= 13) {pos_y = 17;}

    gotoxy(35,14); printf("                  COULEUR DU STADE     ");
    gotoxy(35,15); printf("                 COULEUR DU SERPENT    ");
    gotoxy(35,16); printf("                     DIFFICULTE        ");
    gotoxy(35,17); printf("                       QUITTER         ");

    gotoxy(pos_gauche,pos_y); printf("==>");
    gotoxy(pos_droite,pos_y); printf("<==");

    switch (direction)
    {
    case 2 : pos_y++; break;
    case 3 : pos_y--; break;
    case 4 :
            if (pos_y==14) CHOIX_COULEUR_STADE(PT_ParamJeu);
            if (pos_y==15) CHOIX_COULEUR_SERPENT(PT_ParamJeu);
            if (pos_y==16) CHOIX_DIFFICULTE(PT_ParamJeu);
            if (pos_y==17) quitter = 1;
            break;
    case 5 : quitter = 1;
    }
    }while(quitter == 0);
    cls();
}

void Param_init (TYPE_PARAM_JEU* PT_ParamJeu)
{ (*PT_ParamJeu).couleur_snake = 0; (*PT_ParamJeu).couleur_stade = 4; (*PT_ParamJeu).difficulte = 100;  PT_ParamJeu->H_stade = 25; PT_ParamJeu->L_stade = 100;}

// =============================================================================
// Nom : SP_INIT_PARAMETRES_STADE
// Sémantique : Initialise la couleur du stade
// Paramètres :
// couleur_stade (IN/OUT) – couleur – couleur du stade (interieur)
// Pré-conditions : aucune
// Post-conditions : avoir initialisé chacune des variables
// ============================================================================
// Test
// ============================================================================
// PROCEDURE SP_INIT_PARAMETRES_STADE (couleur_stade (IN-OUT) : réels )

void CHOIX_COULEUR_STADE(TYPE_PARAM_JEU* PT_ParamJeu)
{
    cls();
    int quitter = 0;
    int pos_gauche = 51;
    int pos_droite = 68;
    int pos_y      = 14;

    do {
    int direction = SP_Gestion_Clavier();
    msleep(10);

    if (pos_y >= 22) {pos_y = 14;}
    if (pos_y <= 13) {pos_y = 21;}

    gotoxy(35,11); setColor(GREY)    ; printf("             Choisez la couleur du stade               ");
    gotoxy(35,12); setColor(GREY)    ; printf("Appuyez sur entree pour continuer ou ecape pour quitter");

    gotoxy(35,14); setColor(BLACK)   ; printf("                        NOIR           ");
    gotoxy(35,15); setColor(BLUE)    ; printf("                        BLEU           ");
    gotoxy(35,16); setColor(CYAN)    ; printf("                        CYAN           ");
    gotoxy(35,17); setColor(RED)     ; printf("                        ROUGE          ");
    gotoxy(35,18); setColor(MAGENTA) ; printf("                       MAGENTA         ");
    gotoxy(35,19); setColor(BROWN)   ; printf("                        MARRON         ");
    gotoxy(35,20); setColor(YELLOW)  ; printf("                        JAUNE          ");
    gotoxy(35,21); setColor(WHITE)   ; printf("                        BLANC          ");

    setColor(GREY);
    gotoxy(pos_gauche,pos_y); printf("==>");
    gotoxy(pos_droite,pos_y); printf("<==");

    switch (direction)
    {
    case 2 : pos_y++; break;
    case 3 : pos_y--; break;
    case 4 :
            if (pos_y==14) (*PT_ParamJeu).couleur_stade = 0;  // 0  - Noir
            if (pos_y==15) (*PT_ParamJeu).couleur_stade = 1;  // 1  - Bleu
            if (pos_y==16) (*PT_ParamJeu).couleur_stade = 3;  // 3  - Cyan
            if (pos_y==17) (*PT_ParamJeu).couleur_stade = 4;  // 4  - Rouge
            if (pos_y==18) (*PT_ParamJeu).couleur_stade = 5;  // 5  - Magenta
            if (pos_y==19) (*PT_ParamJeu).couleur_stade = 6;  // 6  - Marron
            if (pos_y==20) (*PT_ParamJeu).couleur_stade = 14; // 14 - Jaune
            if (pos_y==21) (*PT_ParamJeu).couleur_stade = 15; // 15 - Blanc
            if (pos_y==22)  quitter = 1;
            break;
    case 5 : quitter = 1;
    }
    gotoxy(45,24); printf("Couleur STADE :"); setBackgroundColor((*PT_ParamJeu).couleur_stade); gotoxy(61,24); printf("    "); setBackgroundColor(GREEN);
    }while(quitter == 0);
    cls();
}

// =============================================================================
// Nom : SP_INIT_PARAMETRES_SERPENT
// Sémantique : Initialise la couleur du serpent
// Paramètres:
// couleur_snake (IN/OUT) – couleur – couleur du serpent
// Pré-conditions : aucune
// Post-conditions : avoir initialisé chacune des variables
// ============================================================================
// Test
// ============================================================================
// PROCEDURE SP_INIT_PARAMETRES_SERPENT(couleur_snake (IN-OUT) : réels)

void CHOIX_COULEUR_SERPENT(TYPE_PARAM_JEU* PT_ParamJeu)
{
    cls();
    int quitter = 0;
    int pos_gauche = 51;
    int pos_droite = 68;
    int pos_y      = 14;

    do {
    int direction = SP_Gestion_Clavier();
    msleep(10);

    if (pos_y >= 22) {pos_y = 14;}
    if (pos_y <= 13) {pos_y = 21;}

    gotoxy(35,11); setColor(GREY)    ; printf("             Choisez la couleur du serpent               ");
    gotoxy(35,12); setColor(GREY)    ; printf("Appuyez sur entree pour continuer ou ecape pour quitter");

    gotoxy(35,14); setColor(BLACK)   ; printf("                        NOIR           ");
    gotoxy(35,15); setColor(BLUE)    ; printf("                        BLEU           ");
    gotoxy(35,16); setColor(CYAN)    ; printf("                        CYAN           ");
    gotoxy(35,17); setColor(RED)     ; printf("                        ROUGE          ");
    gotoxy(35,18); setColor(MAGENTA) ; printf("                       MAGENTA         ");
    gotoxy(35,19); setColor(BROWN)   ; printf("                        MARRON         ");
    gotoxy(35,20); setColor(YELLOW)  ; printf("                        JAUNE          ");
    gotoxy(35,21); setColor(WHITE)   ; printf("                        BLANC          ");

    setColor(GREY);
    gotoxy(pos_gauche,pos_y); printf("==>");
    gotoxy(pos_droite,pos_y); printf("<==");

    switch (direction)
    {
    case 2 : pos_y++; break;
    case 3 : pos_y--; break;
    case 4 :
            if (pos_y==14) (*PT_ParamJeu).couleur_snake = 0;  // 0  - Noir
            if (pos_y==15) (*PT_ParamJeu).couleur_snake = 1;  // 1  - Bleu
            if (pos_y==16) (*PT_ParamJeu).couleur_snake = 3;  // 3  - Cyan
            if (pos_y==17) (*PT_ParamJeu).couleur_snake = 4;  // 4  - Rouge
            if (pos_y==18) (*PT_ParamJeu).couleur_snake = 5;  // 5  - Magenta
            if (pos_y==19) (*PT_ParamJeu).couleur_snake = 6;  // 6  - Marron
            if (pos_y==20) (*PT_ParamJeu).couleur_snake = 14; // 14 - Jaune
            if (pos_y==21) (*PT_ParamJeu).couleur_snake = 15; // 15 - Blanc
            if (pos_y==22)  quitter = 1;
            break;
    case 5 : quitter = 1;
    }
    gotoxy(45,24); printf("Couleur SERPENT :"); setBackgroundColor((*PT_ParamJeu).couleur_snake); gotoxy(63,24); printf("*****O"); setBackgroundColor(GREEN);
    }while(quitter == 0);
    cls();
}

// =============================================================================
// Nom : SP_INIT_PARAMETRES_DIFFICULTE
// Sémantique : Initialise la valeur de difficulté
// Paramètres:
// difficulte (IN/OUT) – entier – valeur de la difficulté
// Pré-conditions : aucune
// Post-conditions : avoir initialisé chacune des variables
// ============================================================================
// Test
// ============================================================================
// PROCEDURE SP_INIT_PARAMETRES_DIFFICULTE ( difficulte (IN-OUT) : réels )


void CHOIX_DIFFICULTE(TYPE_PARAM_JEU* PT_ParamJeu)
{
    cls();
    char *level = "NORMAL";
    int quitter = 0;
    int pos_gauche = 51;
    int pos_droite = 68;
    int pos_y      = 14;

    do {
    int direction = SP_Gestion_Clavier();
    msleep(50);

    if (pos_y >= 18) {pos_y = 14;}
    if (pos_y <= 13) {pos_y = 17;}

    gotoxy(35,14); printf("                      NORMAL          ");
    gotoxy(35,15); printf("                     DIFFICILE         ");
    gotoxy(35,16); printf("                     IMPOSSIBLE        ");
    gotoxy(35,17); printf("                      QUITTER          ");

    gotoxy(pos_gauche,pos_y); printf("==>");
    gotoxy(pos_droite,pos_y); printf("<==");

    switch (direction)
    {
    case 2 : pos_y++; break;
    case 3 : pos_y--; break;
    case 4 :
            if (pos_y==14) {(*PT_ParamJeu).difficulte = 100;  PT_ParamJeu->H_stade = 25; PT_ParamJeu->L_stade = 100; level="NORMAL";};
            if (pos_y==15) {(*PT_ParamJeu).difficulte = 80;  PT_ParamJeu->H_stade = 25; PT_ParamJeu->L_stade = 80; level="DIFFICILE";}
            if (pos_y==16) {(*PT_ParamJeu).difficulte = 30 ;  PT_ParamJeu->H_stade = 15; PT_ParamJeu->L_stade = 60; level="IMPOSSIBLE";}
            if (pos_y==17)  quitter =1;
            break;
    case 5 : quitter = 1;

    }
    gotoxy(45,22); printf("Difficulte :  %s   ",level);
    }while(quitter == 0);
    cls();
}

/*BLACK (noir)	0
BLUE (bleu)	1
GREEN (vert)	2
CYAN (cyan)	3
RED (rouge)	4
MAGENTA (magenta)	5
BROWN (marron)	6
LIGHTGRAY (gris clair)	7
DARKGRAY (gris foncé)	8
LIGHTBLUE (bleu clair)	9
LIGHTGREEN (vert clair)	10
LIGHTCYAN (cyan clair)	11
LIGHTRED (rouge clair)	12
LIGHTMAGENTA (magenta clair)	13
YELLOW (jaune)	14
WHITE (blanc)	15*/
