#include "Graphisme.h"

////////////////////////////////////////////////////////////////////////////////////////
//                          Constructeurs et Destructeur                              //
////////////////////////////////////////////////////////////////////////////////////////
Graphisme::Graphisme(const std::string cheminData) {
    //Détermination du chemin de base
    chemin = cheminData + "../data/sprites/";

    //VideoMode détermine taille fenetre
    fenetre.create(sf::VideoMode(LARGEUR, HAUTEUR), "TowerForce");

    //Nombre de rafraichissement par seconde
    fenetre.setFramerateLimit(60);

    //Position de la fenetre
    fenetre.setPosition(sf::Vector2i(400, 0));

    //Chargement de l'image pour le fond
    if(!tFond.loadFromFile(chemin + "fond.jpg"))
    {
        std::cout << "Chargement échoué du fond" << std::endl;
        exit(EXIT_FAILURE);
    }
    sprite_fond.setTexture(tFond);

    //Chargement de l'image de level up
    if(!tLvlUp.loadFromFile(chemin + "lvlUp.png"))
    {
        std::cout << "Chargement échoué du LvlUp" << std::endl;
        exit(EXIT_FAILURE);
    }
    sprite_LvlUp.setTexture(tLvlUp);

    setTextureMap(1);

    //Chargement du Font et application sur le texte
    if(!font.loadFromFile(chemin + "../" + FONT))
    {
        std::cout << "Chargement échoué de la police" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Mise à jour de l'icône de l'application dans le coin haut/gauche de la fenêtre
    sf::Image icon;
    if (!icon.loadFromFile(chemin + "../icons/towerforce.png"))
        exit(EXIT_FAILURE);
    fenetre.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    //On initialise une case surbrillante et ses coordonnées
    caseSelection.setSize(sf::Vector2f(TAILLE_SPRITE, TAILLE_SPRITE));
    caseSelection.setPosition(sf::Vector2f(static_cast<float>(0), static_cast<float>(MENUHAUT)));
    Case.setX(0);
    Case.setY(0);

    //Initialisation des boutons
    boutonAchat1.fabriqueBouton("Ameliorer", font);
    boutonAchat2.fabriqueBouton("Ameliorer", font);
    boutonAchat3.fabriqueBouton("Ameliorer", font);
    boutonTourDepart.fabriqueBouton("Acheter", font);
    boutonLvlUp.fabriqueBouton("Ameliorer", font);

    //Chargement de la musique
    if (!music_achat.openFromFile(chemin + "../musique/Music_Achat.ogg"))
    {
        std::cout << "Chargement échoué de la musique" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (!music_main.openFromFile(chemin + "../musique/Epic_Music.ogg"))
    {
        std::cout << "Chargement échoué de la musique" << std::endl;
        exit(EXIT_FAILURE);
    }
    //Faire boucler la musique tout le long du jeu
    music_main.setLoop(true);
    music_main.play();
}

Graphisme::~Graphisme() {

}

////////////////////////////////////////////////////////////////////////////////////////
//                                      Accesseurs                                    //
////////////////////////////////////////////////////////////////////////////////////////
sf::Sprite Graphisme::getFond() const {
    return sprite_fond;
}

sf::Sprite Graphisme::getMap() const {
    return sprite_map;
}

sf::Sprite Graphisme::getSpriteLvlUp() const {
    return sprite_LvlUp;
}

sf::RectangleShape Graphisme::getcaseSelection() const {
    return caseSelection;
}

Point Graphisme::getCase() const {
    return Case;
}

sf::Music& Graphisme::getMusiqueTour() {
    return music_achat;
}

sf::Music& Graphisme::getMusiqueMain() {
    return music_main;
}

////////////////////////////////////////////////////////////////////////////////////////
//                                      Mutateur                                      //
////////////////////////////////////////////////////////////////////////////////////////
void Graphisme::setCase(Point tCase) {
    Case.setX(tCase.getX());
    Case.setY(tCase.getY());
}

void Graphisme::setTextureMap(const uint Niveau) {
    //Chargement de la bonne texture en fonction du niveau en cours
    switch(Niveau)
    {
        case 1:
            //Chargement des images pour la carte
            if(!tCarte.loadFromFile(chemin + "terrainForet.png"))
            {
                std::cout << "Chargement échoué des sprites de la map" << std::endl;
                exit(EXIT_FAILURE);
            }
            break;

        case 2:
            //Chargement des images pour la carte
            if(!tCarte.loadFromFile(chemin + "terrainNeige.png"))
            {
                std::cout << "Chargement échoué des sprites de la map" << std::endl;
                exit(EXIT_FAILURE);
            }
            break;

        case 3:
            //Chargement des images pour la carte
            if(!tCarte.loadFromFile(chemin + "terrainVolcan.png"))
            {
                std::cout << "Chargement échoué des sprites de la map" << std::endl;
                exit(EXIT_FAILURE);
            }
            break;

    }

    sprite_map.setTexture(tCarte);
}

////////////////////////////////////////////////////////////////////////////////////////
//                                  Autres fonctions                                  //
////////////////////////////////////////////////////////////////////////////////////////
void Graphisme::afficheStats(const Jeu &Partie, const uint cas) {
    std::string texte;
    Message mess;

    //Affichage des 4 messages en haut de l'écran
    for (int i=cas; i<4; i++)
    {
        switch (i)
        {
            case 0: //Nb de Vague
                texte = "Vague: " + std::to_string(Partie.getNumVague()) + "/" + std::to_string(Partie.getNbVague());
                mess.initialisation(font, texte, 13, sf::Color::Blue, sf::Vector2f(30, 25), false);
                break;

            case 1:  //Nb d'ennemis
                texte = "Ennemis: " + std::to_string(Partie.getNbEnnemis());
                mess.initialisation(font, texte, 13, sf::Color::Red, sf::Vector2f(200, 25), false);
                break;

            case 2:  //Nb de vie
                texte = "Vie: " + std::to_string(Partie.getVie()) + "/20";
                mess.initialisation(font, texte, 13, sf::Color::Green, sf::Vector2f(360, 25), false);
                break;

            case 3:  //Nb de PO
                texte = "Or: " + std::to_string(Partie.getPO());
                mess.initialisation(font, texte, 13, sf::Color::Yellow, sf::Vector2f(520, 25), false);
                break;
        }

    mess.dessiner(fenetre);
    }
}

void Graphisme::afficheMessage(const uint type, uint time) {
    Message mess;
    std::string messageFin;

    //Affichage du message central en fonction du type demandé
    switch(type)
    {
        case VAGUE:
            messageFin = "Vague finie ! La suite dans : " + std::to_string(5-time) + " sec";
            mess.initialisation(font, messageFin, 16, sf::Color::Green, sf::Vector2f(0,0), true);
            break;

        case MANCHE:
            messageFin = "Niveau fini ! La suite dans : " + std::to_string(5-time) + " sec";
            mess.initialisation(font, messageFin, 16, sf::Color::Green, sf::Vector2f(0,0), true);
            break;

        case PARTIE:
            messageFin = "Vous avez perdu la partie ! Recommencez !";
            mess.initialisation(font, messageFin, 16, sf::Color::Red, sf::Vector2f(0,0), true);
            break;

        case POSER_TOUR:
            messageFin = "Placez vos premieres tours ! Vous avez : " + std::to_string(15-time) + " sec";
            mess.initialisation(font, messageFin, 11, sf::Color::Green, sf::Vector2f(TAILLE_SPRITE-16, 27), false);
            break;

        case FINI:
            messageFin = "Bravo vous avez detruit nos hordes ! Merci d'avoir jouer !";
            mess.initialisation(font, messageFin, 11, sf::Color::Green, sf::Vector2f(0,0), true);
            break;
    }

    mess.dessiner(fenetre);
}

void Graphisme::eventClavier(sf::Event event) {
    //Si le joueur appuie sur ECHAP
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        fenetre.close();
}

void Graphisme::surbrillance() {
    //SI la case est comprise dans la matrice (largeur = 20 et hauteur = 15)
    if(((Case.getX() >= 0) && (Case.getX() < 20)) && ((Case.getY() >= 0) && (Case.getY() < 15)))
        caseSelection.setPosition(sf::Vector2f(static_cast<float>(Case.getX()*TAILLE_SPRITE), static_cast<float>((Case.getY()*TAILLE_SPRITE)+MENUHAUT)));

    typeAchat = RIEN;
}

void Graphisme::eventSouris(sf::Event event, Jeu &Partie) {
    //Si le joueur clique sur la croix
    if (event.type == sf::Event::Closed)
    {
        fenetre.close();
    }

    //Si le joueur clique avec le bouton droit de la souris, il recupere les données de la position de la souris
    else if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
        //Récupération des coordonnées de la souris en pixel
        sf::Vector2i positionSouris = sf::Mouse::getPosition(fenetre);
        //Preparation de variable pour la reposition de la case surbrillante par tuile
        Case.setX(static_cast<int>(floor(positionSouris.x/TAILLE_SPRITE)));
        Case.setY(static_cast<int>(floor((positionSouris.y/TAILLE_SPRITE)-2)));
        surbrillance();
    }

    //Si le joueur clique avec le bouton gauche de la souris
    //il recupere les données de la position de la souris
    else if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        //Récupération des coordonnées de la souris en pixel
        sf::Vector2i positionSouris = sf::Mouse::getPosition(fenetre);
        Tower* t = Partie.getTower(Case);

        //Si le joueur a cliqué sur le bouton d'achat 1
        if(boutonAchat1.aCliquer(positionSouris))
        {
            //Si le joueur a assez d'argent et que la tour a tué assez d'ennemis
            if(static_cast<uint>(Partie.getPO()) >= t->getPrixUpgrade() && t->getNbTues()>=t->getNbTuesUpgrade())
            {
                music_achat.play();
                Partie.transformationTower(Case, SNIPER);
            }

        }

        //Si le joueur a cliqué sur le bouton d'achat 2
        else if(boutonAchat2.aCliquer(positionSouris))
        {
            //Si le joueur a assez d'argent et que la tour a tué assez d'ennemis
            if(static_cast<uint>(Partie.getPO()) >= t->getPrixUpgrade() && t->getNbTues()>=t->getNbTuesUpgrade())
            {
                music_achat.play();
                Partie.transformationTower(Case, MITRAILLETTE);
            }
        }

        //Si le joueur a cliqué sur le bouton d'achat 3
        else if(boutonAchat3.aCliquer(positionSouris))
        {
            //Si le joueur a assez d'argent et que la tour a tué assez d'ennemis
            if(static_cast<uint>(Partie.getPO()) >= t->getPrixUpgrade() && t->getNbTues()>=t->getNbTuesUpgrade())
            {
                music_achat.play();
                Partie.transformationTower(Case, REX);
            }
        }

        //Si le joueur a cliqué sur le bouton d'achat de départ
        else if(boutonTourDepart.aCliquer(positionSouris))
        {
            //Si le joueur clique sur le bouton d'achat, il pose une tour en étant débiter de son prix
            if(Partie.getPO()-50>=0)
            {
                music_achat.play();
                Partie.poserTower(Case);
            }
        }

        //Si le joueur a cliqué sur le bouton d'achat d'amélioration
        else if(boutonLvlUp.aCliquer(positionSouris))
        {
            //Si le joueur a assez d'argent et que la tour a tué assez d'ennemis
            if(static_cast<uint>(Partie.getPO()) >= t->getPrixUpgrade() && t->getNbTues()>=t->getNbTuesUpgrade())
            {
                music_achat.play();
                Partie.setPO(Partie.getPO()-t->getPrixUpgrade());
                t->levelUp();
            }

        }
    }
}

void Graphisme::afficheMatrice(const Jeu &Partie) {
    sf::Sprite Case;

    //On boucle sur la largeur
    for(uint i=0; i<LARGEURMAP; i++)
    {
        //On boucle sur la hauteur
        for(uint j=0; j<HAUTEURMAP; j++)
        {
            //Mise en place du Sprite adapté
            sprite_map.setTextureRect(sf::IntRect(Partie.getInMatrice(j, i) * TAILLE_SPRITE, 0 * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE));
            sprite_map.setPosition(sf::Vector2f(static_cast<float>(i*TAILLE_SPRITE), static_cast<float>(64 + (j*TAILLE_SPRITE))));

            fenetre.draw(sprite_map);
        }
    }
}

void Graphisme::afficheMenuAchat(const Jeu &Partie) {

    //Taille matrice en largeur = 20
    if(((Case.getX() >= 0) && (Case.getX() < 20)) && ((Case.getY() >= 0) && (Case.getY() < 15)))
    {
        //Si la case selectionnée est de l'herbe, de la neige ou une plateforme de lave
        if(Partie.getInMatrice(Case.getY(),Case.getX()) == SOL)
        {
            caseSelection.setFillColor(sf::Color(230,230,0,120));
            fenetre.draw(caseSelection);
            typeAchat = ACHAT;
        }
        //Si la case selectionnée est une tour simple
        else if(Partie.getInMatrice(Case.getY(),Case.getX()) == TOWER)
        {
            caseSelection.setFillColor(sf::Color(25,90,231,120));
            fenetre.draw(caseSelection);
            typeAchat = CHOIX;
        }
        //Si la case selectionnée est une tour spécifique
        else if(Partie.getInMatrice(Case.getY(),Case.getX()) > TOWER && Partie.getInMatrice(Case.getY(),Case.getX()) <= T_REX)
        {
            caseSelection.setFillColor(sf::Color(25,90,231,120));
            fenetre.draw(caseSelection);
            typeAchat = LVLUP;
        }
        //Si l'utilisateur clique sur un endroit non-adapté
        else
        {
            typeAchat = RIEN;
        }
    }

    //On efface la précédente interface
    cacherAllBoutons();

    Message mess;

    //Affichage de l'interface adaptée
    switch(typeAchat)
    {
        case ACHAT:
            mess.initialisation(font, "Construction d'une nouvelle Tour !", 16, sf::Color(238,238,0), sf::Vector2f(TAILLE_SPRITE*3, HAUTEUR_BOUTON-64), false);
            mess.dessiner(fenetre);
            boutonTourDepart.afficheBouton(fenetre, CENTRE);
            break;

        case CHOIX:
            mess.initialisation(font, "Sniper", 9, sf::Color::Blue, sf::Vector2f(TAILLE_SPRITE*2, HAUTEUR_BOUTON-80), false);
            mess.dessiner(fenetre);
            boutonAchat1.afficheBouton(fenetre, GAUCHE);

            mess.initialisation(font, "Mitraillette", 9, sf::Color(238,238,0), sf::Vector2f(TAILLE_SPRITE*9, HAUTEUR_BOUTON-80), false);
            mess.dessiner(fenetre);
            boutonAchat2.afficheBouton(fenetre, CENTRE);

            mess.initialisation(font, "T-Rex", 9, sf::Color::Red, sf::Vector2f(TAILLE_SPRITE*16, HAUTEUR_BOUTON-80), false);
            mess.dessiner(fenetre);
            boutonAchat3.afficheBouton(fenetre, DROITE);
            break;

        case LVLUP:
            //Affichage du titre
            mess.initialisation(font, "Amelioration !", 11, sf::Color(238,238,0), sf::Vector2f(TAILLE_SPRITE*9, HAUTEUR_BOUTON-96), false);
            mess.dessiner(fenetre);
            boutonLvlUp.afficheBouton(fenetre, DROITE);
            break;
    }

    afficheStatsTours(Partie.getTower(Case));
}

////////////////////////////////////////////////////////////////////////////////////////
//                           Autres fonctions privées                                 //
////////////////////////////////////////////////////////////////////////////////////////
void Graphisme::cacherAllBoutons() {
    //Affichage de tous les boutons compris dans la classe
    boutonAchat1.cacherBouton();
    boutonAchat2.cacherBouton();
    boutonAchat3.cacherBouton();
    boutonTourDepart.cacherBouton();
    boutonLvlUp.cacherBouton();
}

void Graphisme::afficheStatsTours(const Tower* Tour) {
    std::string Texte;
    Message mess;

    //Affichage du message en fonction du type d'achat possible pour la case selectionée
    switch(typeAchat)
    {
        case CHOIX:
            Texte = "Experience: " + std::to_string(Tour->getNbTues())+ "/"+std::to_string(Tour->getNbTuesUpgrade());
            mess.initialisation(font, Texte, 8, sf::Color::Yellow, sf::Vector2f(TAILLE_SPRITE*8+20, HAUTEUR_BOUTON-120), false);
            mess.dessiner(fenetre);

            for (uint i=0; i<4; i++)
            {
                switch (i)
                {
                    case 0: //Tour Sniper
                        Texte = "Puissant mais lent";
                        mess.initialisation(font, Texte, 8, sf::Color::Yellow, sf::Vector2f(TAILLE_SPRITE*2-30, HAUTEUR_BOUTON-40), false);
                        break;

                    case 1:  //Tour Mitraillette
                        Texte = "Rapide mais faible";
                        mess.initialisation(font, Texte, 8, sf::Color::Yellow, sf::Vector2f(TAILLE_SPRITE*8+5, HAUTEUR_BOUTON-40), false);
                        break;

                    case 2:  //Tour T-Rex
                        Texte = "Polyvalent";
                        mess.initialisation(font, Texte, 8, sf::Color::Yellow, sf::Vector2f(TAILLE_SPRITE*15+30, HAUTEUR_BOUTON-40), false);
                        break;

                    case 3:  //Affichage du Prix
                        Texte = "Prix : " + std::to_string(Tour->getPrixUpgrade()) + "po";
                        mess.initialisation(font, Texte, 8, sf::Color::Yellow, sf::Vector2f(TAILLE_SPRITE*8+36, HAUTEUR_BOUTON-100), false);
                        break;
                }

                mess.dessiner(fenetre);
            }
            break;

        case LVLUP:
            for (uint i=0; i<7; i++)
            {
                switch (i)
                {
                    case 0: //Niveau de la Tour
                        Texte = "Niveau " + std::to_string(Tour->getLevel());
                        mess.initialisation(font, Texte, 8, sf::Color::Yellow, sf::Vector2f(TAILLE_SPRITE*2, HAUTEUR_BOUTON-100), false);
                        break;

                    case 1:  //PA de la tour
                        Texte = "Puissance: " + std::to_string(Tour->getPA()) +" Degats";
                        mess.initialisation(font, Texte, 8, sf::Color::Yellow, sf::Vector2f(TAILLE_SPRITE*2, HAUTEUR_BOUTON-74), false);
                        break;

                    case 2:  //VA de la tour
                        if(Tour->getVA()<0)
                        {
                            Texte = "Vitesse: 1/"+ std::to_string(Tour->getVA()*(-1)) + "sec";
                        }
                        else
                        {
                            Texte = "Vitesse: "+ std::to_string(Tour->getVA()) + "/sec";
                        }

                        mess.initialisation(font, Texte, 8, sf::Color::Yellow, sf::Vector2f(TAILLE_SPRITE*2, HAUTEUR_BOUTON-48), false);
                        break;


                    case 3:  //Portée de la tour
                        Texte = "Portee: " + std::to_string(Tour->getZone());
                        mess.initialisation(font, Texte, 8, sf::Color::Yellow, sf::Vector2f(TAILLE_SPRITE*2, HAUTEUR_BOUTON-22), false);
                        break;

                    case 4:  //Nb de PX
                        Texte = "Experience: " + std::to_string(Tour->getNbTues()) +"/"+ std::to_string(Tour->getNbTuesUpgrade());
                        mess.initialisation(font, Texte, 8, sf::Color::Yellow, sf::Vector2f(TAILLE_SPRITE*16-10, HAUTEUR_BOUTON-70), false);
                        break;

                    case 5:  //Prix
                        Texte = "Prix : " + std::to_string(Tour->getPrixUpgrade()) + "po";
                        mess.initialisation(font, Texte, 8, sf::Color::Yellow, sf::Vector2f(TAILLE_SPRITE*16-10, HAUTEUR_BOUTON-48), false);
                        break;

                    case 6: //Affichage des degats moyen de la tour

                        if(Tour->getVA()<0)
                        {
                            Texte = "DPS: " + std::to_string(Tour->getPA()/(Tour->getVA()*-1))+" Dmg/sec";
                        }
                        else
                        {
                            Texte = "DPS: " + std::to_string(Tour->getPA()*Tour->getVA())+" Dmg/sec";
                        }

                        mess.initialisation(font, Texte, 8, sf::Color::Yellow, sf::Vector2f(TAILLE_SPRITE*2, HAUTEUR_BOUTON+4), false);
                        break;
                }

                mess.dessiner(fenetre);
            }
            break;

    }
}
