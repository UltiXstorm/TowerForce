#include "Ennemi.h"

////////////////////////////////////////////////////////////////////////////////////////
//                          Constructeurs et Destructeur                              //
////////////////////////////////////////////////////////////////////////////////////////
Ennemi::Ennemi(const uint nID, const uint nType, const Point nCoord, const std::string cheminData, const uint NumVague) {
    //Définition du chemin
    chemin = cheminData;

    //Initialsation des paramètres de base
    ID = nID;
    Type = nType;

    Coord.setX(nCoord.getX());
    Coord.setY(nCoord.getY());

    //Chargement du sprite correspondant au type d'Ennemi à créer
    switch(Type)
    {
        case 0:     //Type Squelette
            if(!tEnnemi.loadFromFile(chemin + "squelette.png"))
            {
                std::cout << "Chargement échoué de l'image ennemi" << std::endl;
                exit(EXIT_FAILURE);
            }
            Loot = 1 + (NumVague * 2);
            PV = static_cast<float>(5.0 + (NumVague * 5));
            PVMax = PV;
            Vitesse = 4;
            VolVie = 1; 
            break;

        case 1:     //Type Squelette avec Chapeau
            if(!tEnnemi.loadFromFile(chemin + "squeletteChapeau.png"))
            {
                std::cout << "Chargement échoué de l'image ennemi" << std::endl;
                exit(EXIT_FAILURE);
            }
            Loot = 5+(NumVague*2);
            PV = static_cast<float>(20 +(NumVague*5));
            PVMax = PV;
            Vitesse = 4;
            VolVie = 2;
            break;

        case 2:     //Type Détraqueur
            if(!tEnnemi.loadFromFile(chemin + "detraqueur.png"))
            {
                std::cout << "Chargement échoué de l'image ennemi" << std::endl;
                exit(EXIT_FAILURE);
            }
            Loot = 2+(NumVague*1);
            PV = static_cast<float>(2 + (NumVague*2));
            PVMax = PV;
            Vitesse = 16;
            VolVie = 1;
            break;

        case 3:     //Type Dragon, c'est le boss intermédiaire que l'on rencontre a plusieurs reprise
            if(!tEnnemi.loadFromFile(chemin + "dragon.png"))
            {
                std::cout << "Chargement échoué de l'image ennemi" << std::endl;
                exit(EXIT_FAILURE);
            }
            Loot = 35 + (NumVague*5);
            PV = static_cast<float>(200 + (NumVague*100));
            PVMax = PV;
            Vitesse = 4;
            VolVie = 5;
            break;

        case 4:     //Type Slime
            if(!tEnnemi.loadFromFile(chemin + "slime.png"))
            {
                std::cout << "Chargement échoué de l'image ennemi" << std::endl;
                exit(EXIT_FAILURE);
            }
            Loot = 1+NumVague;
            PV = static_cast<float>(5 + (NumVague*5));
            PVMax = PV;
            Vitesse = 4;
            VolVie = 1;
            break;

        case 5:     //Type Plante Carnivore
            if(!tEnnemi.loadFromFile(chemin + "plante_carnivore.png"))
            {
                std::cout << "Chargement échoué de l'image ennemi" << std::endl;
                exit(EXIT_FAILURE);
            }
            Loot = 5+ NumVague;
            PV = static_cast<float>(20 +(NumVague*5));
            PVMax = PV;
            Vitesse = 4;
            VolVie = 2;
            break;

        case 6:     //Type Dragon Feu
            if(!tEnnemi.loadFromFile(chemin + "dracaufeu.png"))
            {
                std::cout << "Chargement échoué de l'image ennemi" << std::endl;
                exit(EXIT_FAILURE);
            }
            Loot = 5 + (NumVague*2);
            PV = static_cast<float>(25 + (NumVague*7));
            PVMax = PV;
            Vitesse = 4;
            VolVie = 2;
            break;

        case 7:     //Type Demon, c'est le boss de fin du jeu
            if(!tEnnemi.loadFromFile(chemin + "demon.png"))
            {
                std::cout << "Chargement échoué de l'image ennemi" << std::endl;
                exit(EXIT_FAILURE);
            }
            Loot = 1000+(NumVague*100);
            PV = static_cast<float>(5000 +(NumVague*650));
            PVMax = PV;
            Vitesse = 1;
            VolVie = 20;
            break;
    }

    //Mise en place des paramètres de texture
    sprite_Ennemi.setTexture(tEnnemi);
    sprite_Ennemi.setTextureRect(sf::IntRect(1 * TAILLE_SPRITE, 0 * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE));
    sprite_Ennemi.setPosition(sf::Vector2f(static_cast<float>(Coord.getX()*32), static_cast<float>(Coord.getY()*32)+64));
    anim.x = 1;
    anim.y = Down;
}

Ennemi::~Ennemi() {

}

////////////////////////////////////////////////////////////////////////////////////////
//                                      Accesseurs                                    //
////////////////////////////////////////////////////////////////////////////////////////

Point Ennemi::getCoord() const {
	return Coord;
}

float Ennemi::getPV() const {
    return PV;
}

uint Ennemi::getID() const {
    return ID;
}

uint Ennemi::getVolVie() const {
    return VolVie;
}

uint Ennemi::getLoot() const {
    return Loot;
}

sf::Sprite Ennemi::getSprite() const {
    return sprite_Ennemi;
}

sf::Vector2i Ennemi::getAnim() const {
    return anim;
}

////////////////////////////////////////////////////////////////////////////////////////
//                                      Mutateurs                                     //
////////////////////////////////////////////////////////////////////////////////////////

void Ennemi::setCoord(const Point tCoord) {
	Coord.setX(tCoord.getX());
	Coord.setY(tCoord.getY());
}

void Ennemi::setPV(float nPV) {
    PV = nPV;
}

void Ennemi::setAnimX(uint a) {
    anim.x = a;
}

void Ennemi::setAnimY(uint a) {
    anim.y = a;
}

////////////////////////////////////////////////////////////////////////////////////////
//                                  Autres fonctions                                  //
////////////////////////////////////////////////////////////////////////////////////////

uint Ennemi::recoitDegats(const uint Degats) {
    PV = PV - Degats;

    //Si l'ennemi est en vie, renvoie 0
    if(PV > 0)
        return 0;
    //Sinon renvoie le nombre de pièces d'or qu'il vaut
    else
        return Loot;
}

void Ennemi::changerPosition(int x,int y) {
    //Change la position de l'ennemi avec la position X et Y passé en paramètre
    sprite_Ennemi.setTextureRect(sf::IntRect(anim.x * TAILLE_SPRITE, anim.y * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE));
    sprite_Ennemi.move(sf::Vector2f(static_cast<float>(x*Vitesse), static_cast<float>(y*Vitesse)));

    sf::Vector2f posPixel = sprite_Ennemi.getPosition();
    float moduloX = posPixel.x/TAILLE_SPRITE;
    float moduloY = posPixel.y/TAILLE_SPRITE;

    if(moduloX - floor(moduloX) == 0 && moduloY - floor(moduloY) == 0)
    {
        Point newCoord(Coord.getX()+x,Coord.getY()+y);
        setCoord(newCoord);
    }
}

void Ennemi::afficherEnnemi(sf::RenderWindow &fenetre) {
    fenetre.draw(sprite_Ennemi);

    sf::Vector2f posPixel = sprite_Ennemi.getPosition();

    float x = (posPixel.x)+1;
    float y = (posPixel.y);

    //Initialisation de deux rectangles un en fond rouge et un
    //dynamique rempli de bleu pour symboliser la vie restante
    barreFond.setPosition(sf::Vector2f(x , y));
    barreVie.setPosition(sf::Vector2f(x , y));

    barreFond.setSize(sf::Vector2f(30,3));
    barreFond.setFillColor(sf::Color::Red);

    float coefVie = floor((PV/PVMax)*10);
    barreVie.setSize(sf::Vector2f(3*coefVie,3));
    barreVie.setFillColor(sf::Color::Blue);

    fenetre.draw(barreFond);
    fenetre.draw(barreVie);
}
