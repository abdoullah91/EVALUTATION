#include <stdio.h>
#include "films.h"
#include "jeuxvideo.h"

int main() {
    int choix = -1;

    while (choix != 0) {
        printf("=========================\n");
        printf(" APPLICATION RECOMMANDATIONS\n");
        printf("=========================\n");
        printf("1. Version développeur (Films)\n");
        printf("2. Version développeur (Jeux vidéo)\n");
        printf("3. Version utilisateur\n");
        printf("0. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);
        printf("\n");

        switch (choix) {
            case 1:
                films_menuDeveloppeur();
                break;
            case 2:
                jeuxvideo_menuDeveloppeur();
                break;
            case 3:
                films_menuUtilisateur();
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}
