#ifndef FILMS_H
#define FILMS_H

#define MAX_FILMS 100

typedef struct {
    char titre[100];
    char description[1000];
    char genre[50];
    char acteurs[200];
    float note;
} Film;

extern Film films[MAX_FILMS];
extern int nbFilms;

void films_menuDeveloppeur();
void films_menuUtilisateur();
void films_ajouter();
void films_modifier();
void films_supprimer();
void films_afficher();
void films_genererStatistiques();
void films_rechercher();

#endif
