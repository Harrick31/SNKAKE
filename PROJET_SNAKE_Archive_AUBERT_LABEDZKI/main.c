#include <stdio.h>
#include "mesTypes.h"
#include "myLib.h"
#include "SP_GESTION_JEU.h"
#include<Windows.h>
#include<mmsystem.h>

TYPE_POINT EcranTail;
TYPE_PARAM_JEU paramJeu;

int main()
{
//    fullscreen();

    hidecursor();

    system("color 27");

    TYPE_PARAM_JEU ParamJeu;

    TYPE_JOUEUR Joueur;

    TYPE_SNAKE Snake;

    TYPE_POMME Pomme;

    Param_init(&ParamJeu);

    ACCUEIL(&ParamJeu, &Joueur, &Pomme, &Snake);

    gotoxy(45,30);

    return 0;
}


