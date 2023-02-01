#include <stdio.h>
#include <time.h>
#include "mesTypes.h"
#include "myLib.h"
#include "SP_GESTION_JEU.h"

/*===================================================================================
/ Nom Sémantique : FONCTION SP_Gestion_Clavier

/ Sémantique : Gère la détection des évènements clavier sur les touches de direction

/ Paramètres :
/ direction (OUT) - entier : Contient la direction sollicitée par l'utilisateur
/ DROITE = 0 , GAUCHE = 1 , BAS = 2 , HAUT = 3 et -1 SINON
/ Pré-condition : AUCUNE
/ Post conditions : la direction vaut -1,0,1,2,3
/ ====================================================================================
/ Test : le chiffre renvoyé correspond à la direction appuyée
/ ====================================================================================*/

void ACCUEIL(TYPE_PARAM_JEU* PT_ParamJeu, TYPE_JOUEUR* PT_Joueur, TYPE_POMME* PT_Pomme, TYPE_SNAKE* PT_Snake )
{
    cls();
    int quitter =0;
    int pos_gauche = 52;
    int pos_droite = 67;
    int pos_y      = 14;

    do {
    int direction = SP_Gestion_Clavier();
    msleep(5);

    if (pos_y >= 18) {pos_y = 14;}
    if (pos_y <= 13) {pos_y = 17;}

    gotoxy(42,12); printf("    ! Bienvenue dans le SNAKE 2000 ! ");
    gotoxy(41,14); printf("                 JOUER               ");
    gotoxy(41,15); printf("                 OPTION              ");
    gotoxy(41,16); printf("                 SCORES              ");
    gotoxy(41,17); printf("                 QUITTER             ");

    gotoxy(pos_gauche,pos_y); printf("==>");
    gotoxy(pos_droite,pos_y); printf("<==");

    switch (direction)
    {
    case 2 : pos_y++; break;
    case 3 : pos_y--; break;
    case 4 :
            if (pos_y==14){
            AffichageStade(PT_ParamJeu);
            CreationPomme(PT_Pomme, *PT_ParamJeu);
            AffichagePomme(*PT_Pomme);
            InitialisationSerpent(PT_Snake, *PT_ParamJeu, *PT_Pomme);
            EvolutionSerpent(PT_Snake, *PT_ParamJeu, PT_Pomme);}

            if (pos_y==15) AFFICHER_PARAMETRES(PT_ParamJeu);
            if (pos_y==17) quitter = 1;
            break;
    case 5 : quitter = 1;
    }

    }while (quitter ==0);
}
