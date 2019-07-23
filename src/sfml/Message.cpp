#include "Message.h"

////////////////////////////////////////////////////////////////////////////////////////
//                          Constructeurs et Destructeur                              //
////////////////////////////////////////////////////////////////////////////////////////
Message::Message() {

}

Message::~Message() {

}

////////////////////////////////////////////////////////////////////////////////////////
//                                  Autres fonctions                                  //
////////////////////////////////////////////////////////////////////////////////////////
void Message::initialisation(const sf::Font &font, const std::string txt, uint taille, const sf::Color couleur, const sf::Vector2f position, const bool encadre) {
    //initialisation des paramètres de base
    texte.setFont(font);
    texte.setCharacterSize(taille);
    texte.setString(txt);

   #ifdef __unix__
    texte.setColor(couleur);
   #else
    texte.setFillColor(couleur);
   #endif

    //Si le texte doit être encadré
    if(encadre)
    {
        // Récupère la taille du texte affiché
        sf::FloatRect r = texte.getLocalBounds();

        // Positionne le texte au milieu de l'écran de jeu
        float x = ((HAUTEUR - r.width) / 2)-28;
        float y = ((LARGEUR - r.height) / 2)+32;
        texte.setPosition(x, y);

        // Définition du rectangle noir composant le fond pour afficher le texte
        cadre.setSize(sf::Vector2f(r.width + 18, r.height + 22));
        cadre.setPosition(sf::Vector2f(x - 8, y - 22));
        cadre.setFillColor(sf::Color(0, 0, 0, 170));
    }
    else
    {
        //Cadre hors de la zone affichée à l'écran
        cadre.setPosition(sf::Vector2f(-100,-100));
        texte.setPosition(position);
    }
}

void Message::dessiner(sf::RenderWindow &fenetre) const {
    //Affichage des composants d'un message
    fenetre.draw(cadre);
    fenetre.draw(texte);
}
