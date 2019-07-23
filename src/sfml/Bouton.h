/**
    @brief Classe Bouton
    Gère les boutons des interfaces
    @author p1507711
	@file Bouton.h
	@version 1.0
	@date 2018/02/27
*/

#ifndef Bouton_H_INCLUDED
#define Bouton_H_INCLUDED

#include "../core/Point.h"

/**
    @brief Class Bouton

    Cette classe permet de gerer les boutons de l'interface du jeu.
*/

class Bouton
{
    public:

    /**@brief Constructeur par défault de Bouton
    @param none
    @return none
    @code
    Bouton();
    @endcode
    */
    Bouton();

    /**@brief Destructeur de Bouton
    @param none
    @return none
    @code
    ~Bouton();
    @endcode
    */
    ~Bouton();

    /**@brief Accesseur de la position du bouton
    @param none
    @return [PositionBouton] de type unsigned int
    @code
    uint getPositionBouton() const;
    @endcode
    */
    uint getPositionBouton() const;

    /**@brief Mutateur de la position du bouton
    @param [pos] de type const unsigned int
    @return none
    @code
    void setPositionBouton(const uint pos);
    @endcode
    */
    void setPositionBouton(const uint pos);

    /**@brief Mutateur du texte du bouton
    @param [NewText] de type const String par référence
    @return none
    @code
    void setText(const std::string &NewText);
    @endcode
    */
    void setText(const std::string &NewText);

    /**@brief Rend le bouton inaccessible
    @param none
    @return none
    @code
    void cacherBouton();
    @endcode
    */
    void cacherBouton();

    /**@brief Affiche le bouton a l'ecran
    @param [fenetre] de type RenderWindow (librairie SFML) passé par référence
    @param [pos] de type const unsigned int
    @return none
    @code
    void afficheBouton(sf::RenderWindow &fenetre, const uint pos);
    @endcode
    */
    void afficheBouton(sf::RenderWindow &fenetre, const uint pos);

    /**@brief Fonction de fabrication du bouton
    @param [txt] de type const string par référence
    @param [font] de type const Font (librairie SFML) par référence
    @return none
    @code
    void fabriqueBouton(const std::string &txt, const sf::Font &font);
    @endcode
    */
    void fabriqueBouton(const std::string &txt, const sf::Font &font);

    /**@brief Vérifie si l'utilisateur a cliqué sur le bouton
    @param [positionSouris] de type const sf::Vector2i (librairie SFML) par référence
    @return bool
    @code
    bool aCliquer(const sf::Vector2i &positionSouris);
    @endcode
    */
    bool aCliquer(const sf::Vector2i &positionSouris);

    private:

    sf::RectangleShape Corps;
    sf::Text TextBouton;
    uint PositionBouton;

};


#endif