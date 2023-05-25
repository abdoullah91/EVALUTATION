class Application:
    def __init__(self):
        self.films = []
        self.jeux_video = []

    def lancer_application(self):
        print("L'application a été lancée.")

    def utiliser_application(self):
        while True:
            choix = input("Veuillez sélectionner une option:\n"
                          "1. Ajouter un film\n"
                          "2. Ajouter un jeu vidéo\n"
                          "3. Modifier les informations d'un film\n"
                          "4. Modifier les informations d'un jeu vidéo\n"
                          "5. Supprimer un film\n"
                          "6. Supprimer un jeu vidéo\n"
                          "7. Afficher les informations sur tous les films\n"
                          "8. Afficher les informations sur tous les jeux vidéo\n"
                          "9. Générer des statistiques\n"
                          "0. Quitter l'application\n"
                          "Votre choix: ")

            if choix == "1":
                self.ajouter_film()
            elif choix == "2":
                self.ajouter_jeu_video()
            elif choix == "3":
                self.modifier_informations_film()
            elif choix == "4":
                self.modifier_informations_jeu_video()
            elif choix == "5":
                self.supprimer_film()
            elif choix == "6":
                self.supprimer_jeu_video()
            elif choix == "7":
                self.afficher_informations_films()
            elif choix == "8":
                self.afficher_informations_jeux_video()
            elif choix == "9":
                self.generer_statistiques()
            elif choix == "0":
                break
            else:
                print("Option invalide. Veuillez réessayer.")

    def ajouter_film(self):
        titre = input("Titre du film: ")
        description = input("Description du film: ")
        genre = input("Genre du film: ")
        acteurs = input("Acteurs du film (séparés par des virgules): ")
        realisateurs = input("Réalisateurs du film (séparés par des virgules): ")

        film = Film(titre, description, genre, acteurs.split(","), realisateurs.split(","))
        self.films.append(film)
        print("Le film a été ajouté avec succès.")

    def ajouter_jeu_video(self):
        titre = input("Titre du jeu vidéo: ")
        description = input("Description du jeu vidéo: ")
        genre = input("Genre du jeu vidéo: ")
        plateforme = input("Plateforme du jeu vidéo: ")

        jeu_video = JeuVideo(titre, description, genre, plateforme)
        self.jeux_video.append(jeu_video)
        print("Le jeu vidéo a été ajouté avec succès.")

    def modifier_informations_film(self):
        if self.films:
            self.afficher_informations_films()
            index = int(input("Indiquez l'index du film à modifier: "))
            if 0 <= index < len(self.films):
                film = self.films[index]
                titre = input("Nouveau titre du film: ")
                description = input("Nouvelle description du film: ")
                genre = input("Nouveau genre du film: ")
                acteurs = input("Nouveaux acteurs du film (séparés par des virgules): ")
                realisateurs = input("Nouveaux réalisateurs du film (séparés par des virgules): ")

                film.titre = titre
                film.description = description
                film.genre = genre
                film.acteurs = acteurs.split(",")
                film.realisateurs = realisateurs.split(",")
                print("Les informations du film ont été modifiées avec succès.")
            else:
                print("Index invalide.")
        else:
            print("Aucun film disponible.")

    def modifier_informations_jeu_video(self):
        if self.jeux_video:
            self.afficher_informations_jeux_video()
            index = int(input("Indiquez l'index du jeu vidéo à modifier: "))
            if 0 <= index < len(self.jeux_video):
                jeu_video = self.jeux_video[index]
                titre = input("Nouveau titre du jeu vidéo: ")
                description = input("Nouvelle description du jeu vidéo: ")
                genre = input("Nouveau genre du jeu vidéo: ")
                plateforme = input("Nouvelle plateforme du jeu vidéo: ")

                jeu_video.titre = titre
                jeu_video.description = description
                jeu_video.genre = genre
                jeu_video.plateforme = plateforme
                print("Les informations du jeu vidéo ont été modifiées avec succès.")
            else:
                print("Index invalide.")
        else:
            print("Aucun jeu vidéo disponible.")

    def supprimer_film(self):
        if self.films:
            self.afficher_informations_films()
            index = int(input("Indiquez l'index du film à supprimer: "))
            if 0 <= index < len(self.films):
                film = self.films.pop(index)
                print(f"Le film '{film.titre}' a été supprimé avec succès.")
            else:
                print("Index invalide.")
        else:
            print("Aucun film disponible.")

    def supprimer_jeu_video(self):
        if self.jeux_video:
            self.afficher_informations_jeux_video()
            index = int(input("Indiquez l'index du jeu vidéo à supprimer: "))
            if 0 <= index < len(self.jeux_video):
                jeu_video = self.jeux_video.pop(index)
                print(f"Le jeu vidéo '{jeu_video.titre}' a été supprimé avec succès.")
            else:
                print("Index invalide.")
        else:
            print("Aucun jeu vidéo disponible.")

    def afficher_informations_films(self):
        if self.films:
            print("Informations sur les films:")
            for index, film in enumerate(self.films):
                print(f"Index: {index}")
                print(f"Titre: {film.titre}")
                print(f"Description: {film.description}")
                print(f"Genre: {film.genre}")
                print(f"Acteurs: {', '.join(film.acteurs)}")
                print(f"Réalisateurs: {', '.join(film.realisateurs)}")
                print()
        else:
            print("Aucun film disponible.")

    def afficher_informations_jeux_video(self):
        if self.jeux_video:
            print("Informations sur les jeux vidéo:")
            for index, jeu_video in enumerate(self.jeux_video):
                print(f"Index: {index}")
                print(f"Titre: {jeu_video.titre}")
                print(f"Description: {jeu_video.description}")
                print(f"Genre: {jeu_video.genre}")
                print(f"Plateforme: {jeu_video.plateforme}")
                print()
        else:
            print("Aucun jeu vidéo disponible.")

    def generer_statistiques(self):
        nb_films = len(self.films)
        nb_jeux_video = len(self.jeux_video)

        moyenne_notes_films = 0.0
        total_notes_films = 0.0
        nb_notes_films = 0

        for film in self.films:
            if film.note:
                total_notes_films += film.note
                nb_notes_films += 1

        if nb_notes_films > 0:
            moyenne_notes_films = total_notes_films / nb_notes_films

        print("Statistiques:")
        print(f"Nombre total de films: {nb_films}")
        print(f"Nombre total de jeux vidéo: {nb_jeux_video}")
        print(f"Moyenne des notes des films: {moyenne_notes_films:.2f}")


class Film:
    def __init__(self, titre, description, genre, acteurs, realisateurs):
        self.titre = titre
        self.description = description
        self.genre = genre
        self.acteurs = acteurs
        self.realisateurs = realisateurs
        self.note = None


class JeuVideo:
    def __init__(self, titre, description, genre, plateforme):
        self.titre = titre
        self.description = description
        self.genre = genre
        self.plateforme = plateforme


if __name__ == "__main__":
    app = Application()
    app.lancer_application()
    app.utiliser_application()
