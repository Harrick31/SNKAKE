#include <stdio.h>
#include <time.h>
#include "myLib.h"
#include "SP_GESTION_JEU.h"
#include <string.h>

/*===================================================================================
/ Nom Sémantique : FONCTION AffichageStade

/ Sémantique : Gère la détection des évènements clavier sur les touches de direction

/ Paramètres :
/ direction (OUT) - entier : Contient la direction sollicitée par l'utilisateur
/ DROITE = 0 , GAUCHE = 1 , BAS = 2 , HAUT = 3 et -1 SINON
/ Pré-condition : AUCUNE
/ Post conditions : la direction vaut -1,0,1,2,3
/ ====================================================================================
/ Test : le chiffre renvoyé correspond à la direction appuyée
/ ====================================================================================*/

int AffichageStade(TYPE_PARAM_JEU *PT_Stade){
//
//    PT_Stade->H_stade = 25;
//    PT_Stade->L_stade = 50;

    cls();
    int i, j;

    for(i=0;i<=PT_Stade->H_stade;i++){

        for(j=0;j<=PT_Stade->L_stade;j++){

            if (i==0 || i==PT_Stade->H_stade || j==0 || j==PT_Stade->L_stade){
                setColor((*PT_Stade).couleur_stade);
                gotoxy(j+1,i+1);
                printStadeElement();
            }
            else{
                gotoxy(j+1,i+1);
                printf(" ");
            }
        }
    }
    printf("\n");

    return 0;
}

/*===================================================================================
/ Nom Sémantique : FONCTION EvolutionSerpent

/ Sémantique : Gère la détection des évènements clavier sur les touches de direction

/ Paramètres :
/ direction (OUT) - entier : Contient la direction sollicitée par l'utilisateur
/ DROITE = 0 , GAUCHE = 1 , BAS = 2 , HAUT = 3 et -1 SINON
/ Pré-condition : AUCUNE
/ Post conditions : la direction vaut -1,0,1,2,3
/ ====================================================================================
/ Test : le chiffre renvoyé correspond à la direction appuyée
/ ====================================================================================*/

int RallongerSerpent();

/*===================================================================================
/ Nom Sémantique : FONCTION EvolutionSerpent

/ Sémantique : Gère la détection des évènements clavier sur les touches de direction

/ Paramètres :
/ direction (OUT) - entier : Contient la direction sollicitée par l'utilisateur
/ DROITE = 0 , GAUCHE = 1 , BAS = 2 , HAUT = 3 et -1 SINON
/ Pré-condition : AUCUNE
/ Post conditions : la direction vaut -1,0,1,2,3
/ ====================================================================================
/ Test : le chiffre renvoyé correspond à la direction appuyée
/ ====================================================================================*/

void EvolutionSerpent(TYPE_SNAKE *PT_Snake, TYPE_PARAM_JEU Stade, TYPE_POMME *PT_Pomme){

    int quitter =0;
    int dir=DROITE;
    TYPE_POINT tete;


    do {
        PT_Snake->direction = SP_Gestion_Clavier();
        msleep(Stade.difficulte);
        PT_Snake->old_tail.x = PT_Snake->posTail[0].x;
        PT_Snake->old_tail.y = PT_Snake->posTail[0].y;

        tete.x = PT_Snake->tete.x;
        tete.y = PT_Snake->tete.y;

        switch (PT_Snake->direction)
        {
        case 0  : dir = DROITE; PT_Snake->tete.x++; PT_Snake->sens = 0; if(PT_Snake->direction == PT_Snake->sens) {PT_Snake->tete.x++;};  break;

        case 1  : dir = GAUCHE; PT_Snake->tete.x--; PT_Snake->sens = 1; if(PT_Snake->direction == PT_Snake->sens) {PT_Snake->tete.x--;};  break;

        case 2  : dir = BAS; PT_Snake->tete.y++; PT_Snake->sens = 2; if(PT_Snake->direction == PT_Snake->sens) {PT_Snake->tete.y++;}; break;

        case 3  : dir = HAUT; PT_Snake->tete.y--; PT_Snake->sens = 3; if(PT_Snake->direction == PT_Snake->sens) {PT_Snake->tete.y--;}; break;

        case -1 :
              if (dir == DROITE) {PT_Snake->tete.x++;}
              else if (dir == GAUCHE) {PT_Snake->tete.x--;}
              else if (dir == BAS) {PT_Snake->tete.y++;}
              else if (dir == HAUT) {PT_Snake->tete.y--;}
              break;
        }
        //setColor((*Stade).couleur_serpent) ;

        for (int i=0;i<=PT_Snake->tailLength; i++)
        {
            PT_Snake->posTail[i].x = PT_Snake->posTail[i+1].x;
            PT_Snake->posTail[i].y = PT_Snake->posTail[i+1].y;
        }

        PT_Snake->posTail[PT_Snake->tailLength-1].x = tete.x;
        PT_Snake->posTail[PT_Snake->tailLength-1].y = tete.y;

        if (PT_Snake->tete.y <= 1 || PT_Snake->tete.y >= Stade.H_stade + 1  || PT_Snake->tete.x <= -1 || PT_Snake->tete.x >= Stade.L_stade + 1 ) {quitter =1;}
        if (PT_Snake->tete.y <= 1 || PT_Snake->tete.y >= Stade.H_stade + 1  || PT_Snake->tete.x <= -1 || PT_Snake->tete.x >= Stade.L_stade + 1 ) {quitter =1;}


        if (TestPommeSnake(PT_Snake, PT_Pomme, Stade))// Si Testpomme = Vrai alors on affiche la pomme ailleurs
        {
            CreationPomme(PT_Pomme, Stade);
            AffichagePomme(*PT_Pomme);

            PT_Snake->tailLength++;
            PT_Snake->posTail[PT_Snake->tailLength-1].x = PT_Snake->tete.x;
            PT_Snake->posTail[PT_Snake->tailLength-1].y = PT_Snake->tete.y;

            switch (PT_Snake->direction)
            {
            case 0  : dir = DROITE; PT_Snake->tete.x++; break;

            case 1  : dir = GAUCHE; PT_Snake->tete.x--; break;

            case 2  : dir = BAS; PT_Snake->tete.y++; break;

            case 3  : dir = HAUT; PT_Snake->tete.y--; break;

            case -1 :
                  if (dir == DROITE) {PT_Snake->tete.x++;}
                  else if (dir == GAUCHE) {PT_Snake->tete.x--;}
                  else if (dir == BAS) {PT_Snake->tete.y++;}
                  else if (dir == HAUT) {PT_Snake->tete.y--;}
                  break;
            }
        }

        AffichageSerpent(*PT_Snake, Stade);

    }while(quitter == 0);

    TestFinPartie();

//    cls();
//    gotoxy(35,10); printf("                  GAME OVER                  ");
//    gotoxy(35,11); printf("Appuyez sur n'importe quel touche pour revenir au menu principal  ");
//    getch();
//    cls();
}

void InitialisationSerpent(TYPE_SNAKE *PT_Snake, TYPE_PARAM_JEU Stade, TYPE_POMME Pomme ){

    PT_Snake->SnakeLength = 5;
    PT_Snake->tailLength =  PT_Snake->SnakeLength -1;

    do{
        PT_Snake->tete.x  = random();
        PT_Snake->tete.y  = random();
    }while ( PT_Snake->tete.x < 6 || PT_Snake->tete.x > Stade.L_stade || PT_Snake->tete.y < 2 || PT_Snake->tete.y > Stade.H_stade);

    for (int i=0; i<=PT_Snake->tailLength; i++){

        PT_Snake->posTail[PT_Snake->tailLength-1-i].x = PT_Snake->tete.x-i-1;
        PT_Snake->posTail[PT_Snake->tailLength-1-i].y = PT_Snake->tete.y;
    }

    AffichageSerpent(*PT_Snake,Stade);
    getch();
}

void CreationPomme(TYPE_POMME *PT_Pomme, TYPE_PARAM_JEU Stade)
{
    do{
        PT_Pomme->pos.x  = random();
        PT_Pomme->pos.y  = random();

    }while ( PT_Pomme->pos.x < 6 || PT_Pomme->pos.x > Stade.L_stade || PT_Pomme->pos.y < 3 || PT_Pomme->pos.y > Stade.H_stade);
}

int ModificationDesParametres();

int TestFinPartie()
{
    cls();
    gotoxy(35,10); printf("                  GAME OVER                  ");
    gotoxy(35,11); printf("Appuyez sur n'importe quel touche pour revenir au menu principal  ");
    getch();
    cls();
}




int SauvegardeScore();

int AffichageAccueil();

void AffichageSerpent(TYPE_SNAKE Snake, TYPE_PARAM_JEU Param)
{
    int i ;
    gotoxy(Snake.tete.x,Snake.tete.y);

    setColor(BLUE);
    printSnakeHead();

    for (i=Snake.tailLength-1; i>=0 ; i--)
    {

        gotoxy(Snake.posTail[i].x,Snake.posTail[i].y);
        setColor(Param.couleur_snake);
        printSnakeBody();
    }

    gotoxy(Snake.old_tail.x,Snake.old_tail.y);
    setColor(1);
    printf(" ");
    hidecursor();
}

int TestPommeSnake(TYPE_SNAKE *PT_Snake, TYPE_POMME *PT_Pomme, TYPE_PARAM_JEU Stade)
{
    return PT_Snake->tete.x == PT_Pomme->pos.x && PT_Snake->tete.y == PT_Pomme->pos.y ;
}

int AffichagePomme(TYPE_POMME Pomme)
{
    gotoxy(Pomme.pos.x,Pomme.pos.y);
//    setColor(Pomme.Color);
    printPomme();
    return 0;
}

int AffichageParametres();


int AffichageScore();
