/**
    @brief classe Ennemi
	crée les ennemis utilisés sur le terrain
	@author p1508644
	@file Ennemi.h
	@version 2.3
	@date 2018/02/27
*/

#ifndef Ennemi_H_INCLUDED
#define Ennemi_H_INCLUDED

#include "Point.h"

/**
    @brief Class Ennemi

    Cette classe permet de gérer les ennemis sur le terrain.
*/


class Ennemi
{
    public:
    /**@brief Constructeur avec paramètres de Ennemi
    @param [nID] de type const unsigned int
    @param [nType] de type const unsigned int
    @param [nCoord] de type const Point
    @param [cheminData] de type const string
    @param [NumVague] de type const unsigned int
    @return none
    @code
    Ennemi(const uint nID, const uint nType, const Point nCoord, const std::string cheminData, const uint NumVague);
    @endcode
    */
    Ennemi(const uint nID, const uint nType, const Point nCoord, const std::string cheminData, const uint NumVague);

    /**@brief Destructeur de Ennemi
    @param none
    @return none
    @code
    ~Ennemi();
    @endcode
    */
    ~Ennemi();

	/**@brief Accesseur de coord
    @param none
    @return Point
    @code
    Point getCoord() const;
    @endcode
    */
	Point getCoord() const;

	/**@brief Mutateur de coord
    @param [tCoord] de type const Point
    @return none
    @code
    void setCoord(const Point tCoord) ;
    @endcode
    */
	void setCoord(const Point tCoord) ;

    /**@brief Fonction de Changement de position
    @param [x] de type int
    @param [y] de type int
    @return none
    @code
    void changerPosition(int x, int y);
    @endcode
    */
    void changerPosition(int x, int y);

    /**@brief Accesseur des Points de Vie de l'Ennemi
    @param none
    @return float
    @code
    float getPV() const;
    @endcode
    */
    float getPV() const;

    /**@brief Accesseur de l'Identifiant de l'Ennemi
    @param none
    @return unsigned int
    @code
    uint getID() const;
    @endcode
    */
    uint getID() const;

     /**@brief Accesseur de la capacité de l'ennemis à prendre de la vie
    @param none
    @return unsigned int
    @code
    uint getVolVie() const;
    @endcode
    */
    uint getVolVie() const;

    /**@brief Mutateur des Points de Vie de l'Ennemi
    @param [nPV] de type float
    @return none
    @code
    void setPV(float nPV);
    @endcode
    */
    void setPV(float nPV);

    /**@brief Accesseur du vecteur d'animation de l'Ennemi
    @param none
    @return sf::Vector2i (librairie SFML)
    @code
    sf::Vector2i getAnim() const;
    @endcode
    */
    sf::Vector2i getAnim() const;

    /**@brief Mutateur de la coordonnée X du vecteur d'animation de l'Ennemi
    @param [a] de type unsigned int
    @return none
    @code
    void setAnimX(uint a);
    @endcode
    */
    void setAnimX(uint a);

    /**@brief Mutateur de la coordonnée Y du vecteur d'animation de l'Ennemi
    @param [a] de type unsigned int
    @return none
    @code
    void setAnimY(uint a);
    @endcode
    */
    void setAnimY(uint a);

    /**@brief Accesseur du Sprite de l'Ennemi
    @param none
    @return sf::Sprite (Librairie SFML)
    @code
    sf::Sprite getSprite() const;
    @endcode
    */
    sf::Sprite getSprite() const;

    /**@brief Accesseur de la valeur en Pièces d'Or de l'Ennemi
    @param none
    @return unsigned int, Si l'ennemi est tué renvoie sa valeur en Pièces d'Or et sinon renvoie 0
    @code
    uint getLoot() const;
    @endcode
    */
    uint getLoot() const;

    /**@brief Fonction qui assène des dégats à l'Ennemi
    @param [Degats] de type const unsigned int
    @return const unsigned int, Renvoie la vie actuelle de l'Ennemi après attaque
    @code
    uint recoitDegats(const uint Degats);
    @endcode
    */
    uint recoitDegats(const uint Degats);

    /**@brief Affiche un ennemi sur la carte
    @param [fenetre] de type sf::RenderWindow (librairie SFML) par référence
    @return none
    @code
    void afficherEnnemi(sf::RenderWindow &fenetre);
    @endcode
    */
    void afficherEnnemi(sf::RenderWindow &fenetre);

    private:

    std::string chemin;
    uint ID, Type, Loot, VolVie;
    int Vitesse;
    float PV,PVMax;
    Point Coord;

    sf::Texture tEnnemi;
    sf::Sprite sprite_Ennemi;
    sf::Vector2i anim;

    sf::RectangleShape barreFond;
    sf::RectangleShape barreVie;

};

#endif


