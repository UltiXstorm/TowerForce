#include "Bouton.h"

////////////////////////////////////////////////////////////////////////////////////////
//                          Constructeurs et Destructeur                              //
////////////////////////////////////////////////////////////////////////////////////////
Bouton::Bouton() {

}

Bouton::~Bouton() {

}

////////////////////////////////////////////////////////////////////////////////////////
//                                      Accesseurs                                    //
////////////////////////////////////////////////////////////////////////////////////////
uint Bouton::getPositionBouton() const {
    return PositionBouton;
}

////////////////////////////////////////////////////////////////////////////////////////
//                                      Mutateur                                      //
////////////////////////////////////////////////////////////////////////////////////////
void Bouton::setPositionBouton(const uint pos) {
    //Les positions sont déterminées à l'aide d'un enum
    switch (pos) {
        case GAUCHE:
            TextBouton.setPosition(sf::Vector2f(TAILLE_SPRITE*2, HAUTEUR_BOUTON));
            Corps.setPosition(sf::Vector2f(TAILLE_SPRITE*2-10, HAUTEUR_BOUTON-12));
            break;

        case CENTRE:
            TextBouton.setPosition(sf::Vector2f(TAILLE_SPRITE*9, HAUTEUR_BOUTON));
            Corps.setPosition(sf::Vector2f(TAILLE_SPRITE*9-10, HAUTEUR_BOUTON-12));
            break;

        case DROITE:
            TextBouton.setPosition(sf::Vector2f(TAILLE_SPRITE*16, HAUTEUR_BOUTON));
            Corps.setPosition(sf::Vector2f(TAILLE_SPRITE*16-10, HAUTEUR_BOUTON-12));
            break;
    }

    PositionBouton = pos;
}

void Bouton::setText(const std::string &NewText) {
    TextBouton.setString(NewText);
}

////////////////////////////////////////////////////////////////////////////////////////
//                                  Autres fonctions                                  //
////////////////////////////////////////////////////////////////////////////////////////
void Bouton::cacherBouton() {
    //Pour "cacher" le bouton, on le déplace dans un endroit inaccessible pour l'utilisateur
    Corps.setPosition(sf::Vector2f(-150,-150));
}

void Bouton::afficheBouton(sf::RenderWindow &fenetre, const uint pos) {
    //Mise en place de la position + affichage de tous les composants d'un bouton
    setPositionBouton(pos);
    fenetre.draw(Corps);
    fenetre.draw(TextBouton);
}

void Bouton::fabriqueBouton(const std::string &txt, const sf::Font &font) {
    //Initialisation du texte du bouton
    TextBouton.setFont(font);
    TextBouton.setString(txt);

   #ifdef __unix__
    TextBouton.setColor(sf::Color::Black);
   #else
    TextBouton.setFillColor(sf::Color::Black);
   #endif

    TextBouton.setCharacterSize(8);

    //Initialisation du corps du bouton de choix d'amélioration
    sf::FloatRect r = TextBouton.getLocalBounds();
    Corps.setSize(sf::Vector2f(r.width + 20, r.height + 15));
    Corps.setFillColor(sf::Color(238,238,0));
}

bool Bouton::aCliquer(const sf::Vector2i &positionSouris) {
    //Recupération du rectangle composant le texte
    sf::FloatRect r = TextBouton.getLocalBounds();

    //On vérifie que la souris a cliqué dans la zone du rectangle r
    if(positionSouris.x >= Corps.getPosition().x && positionSouris.x <= (Corps.getPosition().x+(r.width + 20)) && positionSouris.y >= Corps.getPosition().y && positionSouris.y <= (Corps.getPosition().y+(r.height + 15)))
        return true;
    else
        return false;
}
