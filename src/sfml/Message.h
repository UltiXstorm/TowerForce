/**
    @brief Classe Bouton
    Gère les boutons des interfaces
    @author p1508644
	@file Bouton.h
	@version 1.0
	@date 2018/02/27
*/

#ifndef Message_H_INCLUDED
#define Message_H_INCLUDED

#include "../core/Point.h"

/**
    @brief Class Message

    Cette classe permet de gérer les messages qui s'affiche à l'écran.
*/

class Message
{
    public:

    /**@brief Constructeur par défault de Message
    @param none
    @return none
    @code
    Message();
    @endcode
    */
    Message();

    /**@brief Destructeur de Message
    @param none
    @return none
    @code
    ~Message();
    @endcode
    */
    ~Message();

    /**@brief Initialise les paramètres d'un message
    @param [font] de type const sf::Font (librairie SFML par référence)
    @param [txt] de type const string
    @param [taille] de type unsigned int
    @param [couleur] de type const sf::Color (librairie SFML)
    @param [position] de type const sf::Vector2f (librairie SFML)
    @param [encadre] de type const bool
    @return none
    @code
    void initialisation(const sf::Font &font, const std::string txt, uint taille, const sf::Color couleur, const sf::Vector2f position, const bool encadre);
    @endcode
    */
    void initialisation(const sf::Font &font, const std::string txt, uint taille, const sf::Color couleur, const sf::Vector2f position, const bool encadre);

    /**@brief Dessine les composants du message
    @param [fenetre] de type sf::RenderWindow (librairie SFML) par référence
    @return none
    @code
    void dessiner(sf::RenderWindow &fenetre) const;
    @endcode
    */
    void dessiner(sf::RenderWindow &fenetre) const;


    private:

    sf::Text texte;
    sf::RectangleShape cadre;

};


#endif