#include <stdio.h>
#include <string.h>
#include "films.h"

Film films[MAX_FILMS];
int nbFilms = 0;

void films_menuDeveloppeur() {
    int choix = -1;

    while (choix != 0) {
        printf("=========================\n");
        printf(" VERSION DÉVELOPPEUR (FILMS)\n");
        printf("=========================\n");
        printf("1. Ajouter un film\n");
        printf("2. Modifier un film\n");
        printf("3. Supprimer un film\n");
        printf("0. Retour\n");
        printf("Choix : ");
        scanf("%d", &choix);
        printf("\n");

        switch (choix) {
            case 1:
                films_ajouter();
                break;
            case 2:
                films_modifier();
                break;
            case 3:
                films_supprimer();
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

void films_menuUtilisateur() {
    int choix = -1;

    while (choix != 0) {
        printf("=========================\n");
        printf(" VERSION UTILISATEUR (FILMS)\n");
        printf("=========================\n");
        printf("1. Afficher les films\n");
        printf("2. Générer des statistiques\n");
        printf("3. Rechercher un film\n");
        printf("0. Retour\n");
        printf("Choix : ");
        scanf("%d", &choix);
        printf("\n");

        switch (choix) {
            case 1:
                films_afficher();
                break;
            case 2:
                films_genererStatistiques();
                break;
            case 3:
                films_rechercher();
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

void films_ajouter() {
    if (nbFilms >= MAX_FILMS) {
        printf("La limite de films a été atteinte. Impossible d'ajouter un nouveau film.\n");
        return;
    }

    Film film;

    printf("===== Ajouter un film =====\n");

    printf("Titre : ");
    scanf(" %[^\n]", film.titre);

    printf("Description : ");
    scanf(" %[^\n]", film.description);

    printf("Genre : ");
    scanf(" %[^\n]", film.genre);

    printf("Acteurs : ");
    scanf(" %[^\n]", film.acteurs);

    printf("Note : ");
    scanf("%f", &film.note);

    films[nbFilms++] = film;

    printf("Le film a été ajouté avec succès.\n");
}

void films_modifier() {
    int i;
    char titre[100];

    printf("===== Modifier un film =====\n");

    printf("Titre du film à modifier : ");
    scanf(" %[^\n]", titre);

    for (i = 0; i < nbFilms; i++) {
        if (strcmp(films[i].titre, titre) == 0) {
            Film film;

            printf("Nouveau titre : ");
            scanf(" %[^\n]", film.titre);

            printf("Nouvelle description : ");
            scanf(" %[^\n]", film.description);

            printf("Nouveau genre : ");
            scanf(" %[^\n]", film.genre);

            printf("Nouveaux acteurs : ");
            scanf(" %[^\n]", film.acteurs);

            printf("Nouvelle note : ");
            scanf("%f", &film.note);

            films[i] = film;

            printf("Le film a été modifié avec succès.\n");
            return;
        }
    }

    printf("Film introuvable.\n");
}

void films_supprimer() {
    int i;
    char titre[100];

    printf("===== Supprimer un film =====\n");

    printf("Titre du film à supprimer : ");
    scanf(" %[^\n]", titre);

    for (i = 0; i < nbFilms; i++) {
        if (strcmp(films[i].titre, titre) == 0) {
            int j;

            for (j = i; j < nbFilms - 1; j++) {
                films[j] = films[j + 1];
            }

            nbFilms--;

            printf("Le film a été supprimé avec succès.\n");
            return;
        }
    }

    printf("Film introuvable.\n");
}

void films_afficher() {
    int i;

    printf("===== Liste des films =====\n");

    if (nbFilms == 0) {
        printf("Aucun film disponible.\n");
        return;
    }

    for (i = 0; i < nbFilms; i++) {
        printf("Titre : %s\n", films[i].titre);
        printf("Description : %s\n", films[i].description);
        printf("Genre : %s\n", films[i].genre);
        printf("Acteurs : %s\n", films[i].acteurs);
        printf("Note : %.2f\n\n", films[i].note);
    }
}

void films_genererStatistiques() {
    int i;
    float totalNotes = 0.0;
    float moyenneNotes;

    printf("===== Statistiques des films =====\n");

    if (nbFilms == 0) {
        printf("Aucun film disponible.\n");
        return;
    }

    printf("Nombre total de films : %d\n", nbFilms);

    for (i = 0; i < nbFilms; i++) {
        totalNotes += films[i].note;
    }

    moyenneNotes = totalNotes / nbFilms;

    printf("Moyenne des notes : %.2f\n", moyenneNotes);
}

void films_rechercher() {
    char titre[100];
    int i;

    printf("===== Rechercher un film =====\n");

    printf("Titre du film : ");
    scanf(" %[^\n]", titre);

    for (i = 0; i < nbFilms; i++) {
        if (strcmp(films[i].titre, titre) == 0) {
            printf("Titre : %s\n", films[i].titre);
            printf("Description : %s\n", films[i].description);
            printf("Genre : %s\n", films[i].genre);
            printf("Acteurs : %s\n", films[i].acteurs);
            printf("Note : %.2f\n", films[i].note);
            return;
        }
    }

    printf("Film introuvable.\n");
}
