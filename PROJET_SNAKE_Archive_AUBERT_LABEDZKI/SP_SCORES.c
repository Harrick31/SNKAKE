#include <stdio.h>
#include <time.h>
#include "myLib.h"
#include "mesTypes.h"
#include "SP_GESTION_JEU.h"

/*===================================================================================
/ Nom S�mantique : FONCTION SP_Gestion_Clavier

/ S�mantique : G�re la d�tection des �v�nements clavier sur les touches de direction

/ Param�tres :
/ direction (OUT) - entier : Contient la direction sollicit�e par l'utilisateur
/ DROITE = 0 , GAUCHE = 1 , BAS = 2 , HAUT = 3 et -1 SINON
/ Pr�-condition : AUCUNE
/ Post conditions : la direction vaut -1,0,1,2,3
/ ====================================================================================
/ Test : le chiffre renvoy� correspond � la direction appuy�e
/ ====================================================================================*/
