#ifndef SP_JEU_H_INCLUDED
#define SP_JEU_H_INCLUDED
#include "mesTypes.h"

    int SP_Gestion_Clavier();

// Déclaration des sous programmes "ACCUEIL"

void ACCUEIL(TYPE_PARAM_JEU* PT_ParamJeu, TYPE_JOUEUR* PT_Joueur, TYPE_POMME* PT_POMME, TYPE_SNAKE* PT_SNAKE);

// Déclaration des sous programmes "JOUER"

int AffichageStade(TYPE_PARAM_JEU*);

int AffichagePomme(TYPE_POMME);

void AffichageSerpent(TYPE_SNAKE, TYPE_PARAM_JEU);

void InitialisationSerpent(TYPE_SNAKE*, TYPE_PARAM_JEU, TYPE_POMME);

void EvolutionSerpent(TYPE_SNAKE*, TYPE_PARAM_JEU, TYPE_POMME*);

void CreationPomme(TYPE_POMME*, TYPE_PARAM_JEU);

int TestPommeSnake(TYPE_SNAKE*, TYPE_POMME*,TYPE_PARAM_JEU);

// Déclaration des sous programmes "SCORES"



// Déclaration des sous programmes "MENU"

    void AFFICHER_PARAMETRES    (TYPE_PARAM_JEU*);

    void CHOIX_COULEUR_STADE    (TYPE_PARAM_JEU*);

    void CHOIX_COULEUR_SERPENT  (TYPE_PARAM_JEU*);

    void CHOIX_DIFFICULTE       (TYPE_PARAM_JEU*);

    void Param_init             (TYPE_PARAM_JEU*);

#endif // SP_JEU_H_INCLUDED
