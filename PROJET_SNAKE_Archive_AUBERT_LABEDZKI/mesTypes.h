#ifndef MESTYPES_H_INCLUDED
#define MESTYPES_H_INCLUDED


//*********************
// structure POINT (x,y)
//*********************
typedef struct {
     int x;
     int y;
} TYPE_POINT;


//*********************
// PARAMETRES de JEU
//*********************
typedef struct {
     int couleur_stade;
     int couleur_snake;
     int Min_stade;
     int Max_stade;
     int difficulte;
     int H_stade;
     int L_stade;
     TYPE_POINT EcranJeu;


} TYPE_PARAM_JEU;

//******************
// DONNEES JOUEUR
//******************
typedef struct {
     char nom[20];
     int score;
} TYPE_JOUEUR;

//******************
// DONNEES SNAKE
//******************
typedef struct {

    TYPE_POINT tete;
    TYPE_POINT old_tail;
    TYPE_POINT posTail[30];
    TYPE_POINT old_posTail[30];
    int direction;
    int tailLength;
    int SnakeLength;
    int vitesse;
    int sens;
    int score;

} TYPE_SNAKE;

//******************
// DONNEES POMME
//******************
 typedef struct {
    TYPE_POINT pos;
    TYPE_POINT pos_bad;
    TYPE_POINT old_bad_pos;
} TYPE_POMME;

#endif // MESTYPES_H_INCLUDED
