#include <stdio.h>
#include <string.h>
#include "jeuxvideo.h"

JeuVideo jeuxVideo[MAX_JEUX_VIDEO];
int nbJeuxVideo = 0;

void jeuxvideo_menuDeveloppeur() {
    int choix = -1;

    while (choix != 0) {
        printf("=========================\n");
        printf(" VERSION DÉVELOPPEUR (JEUX VIDÉO)\n");
        printf("=========================\n");
        printf("1. Ajouter un jeu vidéo\n");
        printf("2. Modifier un jeu vidéo\n");
        printf("3. Supprimer un jeu vidéo\n");
        printf("0. Retour\n");
        printf("Choix : ");
        scanf("%d", &choix);
        printf("\n");

        switch (choix) {
            case 1:
                jeuxvideo_ajouter();
                break;
            case 2:
                jeuxvideo_modifier();
                break;
            case 3:
                jeuxvideo_supprimer();
                break;
            case 0:
                printf("Retour au menu principal.\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }

        printf("\n");
    }
}

void jeuxvideo_ajouter() {
    if (nbJeuxVideo >= MAX_JEUX_VIDEO) {
        printf("La limite de jeux vidéo a été atteinte. Impossible d'ajouter un nouveau jeu vidéo.\n");
        return;
    }

    JeuVideo jeuVideo;

    printf("===== Ajouter un jeu vidéo =====\n");

    printf("Titre : ");
    scanf(" %[^\n]", jeuVideo.titre);

    printf("Description : ");
    scanf(" %[^\n]", jeuVideo.description);

    printf("Genre : ");
    scanf(" %[^\n]", jeuVideo.genre);

    printf("Plateforme : ");
    scanf(" %[^\n]", jeuVideo.plateforme);

    printf("Acteurs : ");
    scanf(" %[^\n]", jeuVideo.acteurs);

    printf("Réalisateurs : ");
    scanf(" %[^\n]", jeuVideo.realisateurs);

    printf("Note : ");
    scanf("%f", &jeuVideo.note);

    jeuxVideo[nbJeuxVideo++] = jeuVideo;

    printf("Le jeu vidéo a été ajouté avec succès.\n");
}

void jeuxvideo_modifier() {
    int i;
    char titre[100];

    printf("===== Modifier un jeu vidéo =====\n");

    printf("Titre du jeu vidéo à modifier : ");
    scanf(" %[^\n]", titre);

    for (i = 0; i < nbJeuxVideo; i++) {
        if (strcmp(jeuxVideo[i].titre, titre) == 0) {
            JeuVideo jeuVideo;

            printf("Nouveau titre : ");
            scanf(" %[^\n]", jeuVideo.titre);

            printf("Nouvelle description : ");
            scanf(" %[^\n]", jeuVideo.description);

            printf("Nouveau genre : ");
            scanf(" %[^\n]", jeuVideo.genre);

            printf("Nouvelle plateforme : ");
            scanf(" %[^\n]", jeuVideo.plateforme);

            printf("Nouveaux acteurs : ");
            scanf(" %[^\n]", jeuVideo.acteurs);

            printf("Nouveaux réalisateurs : ");
            scanf(" %[^\n]", jeuVideo.realisateurs);

            printf("Nouvelle note : ");
            scanf("%f", &jeuVideo.note);

            jeuxVideo[i] = jeuVideo;

            printf("Le jeu vidéo a été modifié avec succès.\n");
            return;
        }
    }

    printf("Jeu vidéo introuvable.\n");
}

void jeuxvideo_supprimer() {
    int i;
    char titre[100];

    printf("===== Supprimer un jeu vidéo =====\n");

    printf("Titre du jeu vidéo à supprimer : ");
    scanf(" %[^\n]", titre);

    for (i = 0; i < nbJeuxVideo; i++) {
        if (strcmp(jeuxVideo[i].titre, titre) == 0) {
            int j;

            for (j = i; j < nbJeuxVideo - 1; j++) {
                jeuxVideo[j] = jeuxVideo[j + 1];
            }

            nbJeuxVideo--;

            printf("Le jeu vidéo a été supprimé avec succès.\n");
            return;
        }
    }

    printf("Jeu vidéo introuvable.\n");
}

void jeuxvideo_afficher() {
    int i;

    printf("===== Liste des jeux vidéo =====\n");

    if (nbJeuxVideo == 0) {
        printf("Aucun jeu vidéo disponible.\n");
        return;
    }

    for (i = 0; i < nbJeuxVideo; i++) {
        printf("Titre : %s\n", jeuxVideo[i].titre);
        printf("Description : %s\n", jeuxVideo[i].description);
        printf("Genre : %s\n", jeuxVideo[i].genre);
        printf("Plateforme : %s\n", jeuxVideo[i].plateforme);
        printf("Acteurs : %s\n", jeuxVideo[i].acteurs);
        printf("Réalisateurs : %s\n", jeuxVideo[i].realisateurs);
        printf("Note : %.2f\n\n", jeuxVideo[i].note);
    }
}

void jeuxvideo_genererStatistiques() {
    int i;
    float totalNotes = 0.0;
    float moyenneNotes;

    printf("===== Statistiques des jeux vidéo =====\n");

    if (nbJeuxVideo == 0) {
        printf("Aucun jeu vidéo disponible.\n");
        return;
    }

    printf("Nombre total de jeux vidéo : %d\n", nbJeuxVideo);

    for (i = 0; i < nbJeuxVideo; i++) {
        totalNotes += jeuxVideo[i].note;
    }

    moyenneNotes = totalNotes / nbJeuxVideo;

    printf("Moyenne des notes : %.2f\n", moyenneNotes);
}

void jeuxvideo_rechercher() {
    char titre[100];
    int i;

    printf("===== Rechercher un jeu vidéo =====\n");

    printf("Titre du jeu vidéo : ");
    scanf(" %[^\n]", titre);

    for (i = 0; i < nbJeuxVideo; i++) {
        if (strcmp(jeuxVideo[i].titre, titre) == 0) {
            printf("Titre : %s\n", jeuxVideo[i].titre);
            printf("Description : %s\n", jeuxVideo[i].description);
            printf("Genre : %s\n", jeuxVideo[i].genre);
            printf("Plateforme : %s\n", jeuxVideo[i].plateforme);
            printf("Acteurs : %s\n", jeuxVideo[i].acteurs);
            printf("Réalisateurs : %s\n", jeuxVideo[i].realisateurs);
            printf("Note : %.2f\n", jeuxVideo[i].note);
            return;
        }
    }

    printf("Jeu vidéo introuvable.\n");
}
