#ifndef JEUXVIDEO_H
#define JEUXVIDEO_H

#define MAX_JEUX_VIDEO 100

typedef struct {
    char titre[100];
    char description[1000];
    char genre[50];
    char plateforme[50];
    char acteurs[200];
    char realisateurs[200];
    float note;
} JeuVideo;

extern JeuVideo jeuxVideo[MAX_JEUX_VIDEO];
extern int nbJeuxVideo;

void jeuxvideo_menuDeveloppeur();
void jeuxvideo_ajouter();
void jeuxvideo_modifier();
void jeuxvideo_supprimer();
void jeuxvideo_afficher();
void jeuxvideo_genererStatistiques();
void jeuxvideo_rechercher();

#endif
