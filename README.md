# Introduction

Ce Tower Defense a été conçu et développé dans le cadre de l'UE **"LIFAP4 : Conception et développement d'applications"** lors du semestre de printemps 2018 à l'Université Lyon 1 Claude Bernard par les étudiants *CORAZZA Charlotte* (p1508644), *TREME Guillaume* (p1507711) et *MARTIN Gaulthier* (p1508579).

Pour l'affichage graphique, nous avons utilisé la **bibliothèque graphique SFML** que vous pouvez retrouver ici : https://www.sfml-dev.org/index-fr.php. Si vous êtes sur une distribution Unix vous pouvez l'installer avec la commande "sudo apt-get install libsfml-dev".

## Configuration Linux
Pour jouer, il vous suffit de lancer la commande "make lancer" dans un terminal ou de double-cliquer sur l'executable TowerForce contenu dans le dossier ./bin.
La commande "make lancer" effectue une compilation complète des fichiers puis lance automatiquement l'exécutable.

## Configuration Windows (64 bits uniquement)
Il vous suffit de double-cliquer sur l'exécutable TowerForce dans le dossier ./x64 pour lancer une partie.
Pour la compilation : ouvrir le fichier TowerForce.sln avec Visual Studio 2015. Ne pas oublier de recopier les dll du répertoire ./SFML-2.4.2/bin dans le répertoire de l'exécutable Windows (./x64).

Nous vous souhaitons du bon temps sur notre application.

N'en laissez passer aucun et bon jeu !

# Didacticiel de jeu
Vous trouverez ici toutes les informations vous permettant de savoir jouer !
Tout d'abord, en lançant une partie, vous aurez 15 secondes pour placer comme vous le souhaitez vos tours en fonction de votre quantité de pièces d'or de départ.

Pour sélectionner une case sur la carte, mettez votre curseur sur celle-ci et faites un clic droit. Un carré coloré vous indiquera votre selection. Si cette case est valable, un menu d'achat s'affichera en bas de votre écran. Pour acheter, faites un clic gauche sur le bouton acheter. Vous ne pouvez poser une Tour que sur un terrain plat.

Chaque Tour peut ensuite ếtre améliorée en Tour spécifique. Il y a trois catégories :

* Tour Snipe : elle a un grand rayon, fait énormément de dégats mais tire lentement.

* Tour Mitraillette : elle a un petit rayon, fait des dégats faible mais tir très vite.

* Tour T-Rex : elle a un rayon moyen, fait beaucoup de points de dégats et tir à vitesse moyenne.

Chaque Tour pourra ensuite être améliorée avec des pièces d'or et un nombre d'ennemis tués.

Un petit voyant sur la gauche de la tour indique que celle-ci peut être améliorée.

Enfin pour les prix :

* Tour de départ : 50 pièces d'or

* Transformation de Tour : 25 pièces d'or

* Améliorations de Tour : le prix dépend du niveau actuel de la tour et est affiché dans le menu d'amélioration

# Contenu de l'archive
Voici un récapitulatif de tout ce que vous pourrez trouver dans ce dossier. Les noms de dossier sont écrits en majuscule pour faciliter la compréhension.

* BIN
    * TowerForce (exécutable)

* DATA
    * ICONS
        * towerforce.ico
        * towerforce.png

    * MUSIQUE
        * Epic_Music.ogg
        * Music_Achat.ogg

    * NIVEAUX
        * niveau1.txt
        * niveau2.txt
        * niveau3.txt

    * POLICE
        * emmasophia.ttf

    * SPRITES
        * demon.png
        * detraqueur.png
        * dracaufeu.png
        * dragon.png
        * fond.jpg
        * lvlUp.png
        * plante_carnivore.png
        * slime.png
        * squelette.png
        * squeletteChapeau.png
        * terrainForet.png
        * terrainNeige.png
        * terrainVolcan.png

    * VAGUES
        * niveau1.txt
        * niveau2.txt
        * niveau3.txt

* DOC
    * HTML
        * toute la documentation nécessaire à Doxygen
	* image.doxy

* OBJ
    * Bouton.o
    * Ennemi.o
	* Graphisme.o
	* Jeu.o
	* main.o
    * Message.o
	* Point.o
	* Tower.o

* SRC
    * CORE
        * Constantes.h
        * Ennemi.cpp
        * Ennemi.h
        * Jeu.cpp
        * Jeu.h
        * Point.cpp
        * Point.h
        * Tower.cpp
        * Tower.h

    * SFML
        * Graphisme.cpp
        * Graphisme.h
        * Bouton.cpp
        * Bouton.h
        * Message.cpp
        * Message.h

	* TESTREGRESSION
        * testsClasse.cpp

	* main.cpp
    * towerforce.rc

* Makefile
* README.html
* README.md
* TowerForce.sln
* TowerForce.vcxproj


# Choix de conception
## Les fichiers de niveau
Nos différentes cartes de niveau sont éditées suivant un fichier texte avec un format particulier détaillé ici :

* Première ligne : coordonnées du point de départ du parcours X puis Y

* 15 lignes suivantes : détaille de la matrice génératrice d'affichage grâce à des numéros. Chaque chiffre correspond à une tuile particulier à afficher. Par exemple 6 = Sol ; 23 = porte de fin ; etc...

Contraintes :

* Le chemin des ennemis doit impérativement commencer par la gauche et finir sur la droite.

* Il ne doit y avoir ni division ni croisements dans le chemin à emprunter.

## Les fichiers de vague
Chaque niveau à un fichier de vague d'ennemis associé s'écrivant sous cette forme :

* Première ligne : Nombre de vague

* Chaque ligne suivante décrit la vague dans cet ordre :
    * Nombre d'ennemi Dragon
    * Nombre d'ennemi Squelette
    * Nombre d'ennemi Squelette avec chapeau
    * Nombre d'ennemi Slime
    * Nombre d'ennemi Plante Carnivore
    * Nombre d'ennemi Dracaufeu
    * Nombre d'ennemi Demon
    * Nombre d'ennemi Détraqueur
