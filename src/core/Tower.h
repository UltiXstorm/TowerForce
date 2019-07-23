
/**
    @brief classe Tower
	crée les tours
	@author p1507711
	@file Tower.h
	@version 1.0
	@date 2018/02/27
*/

#ifndef Tower_H_INCLUDED
#define Tower_H_INCLUDED

#include "Point.h"


/**
    @brief Class Tower

    Cette classe permet de gerer les Tours.
*/


class Tower {

public:

	/**@brief Constructeur avec paramètres de Tower
    @param [Id] de type const unsigned int
    @param [Position] de type const Point
    @param [cheminData] de type const string
    @return none
    @code
    Tower(const uint Id, const uint Type, const Point Position);
    @endcode
    */
	Tower(const uint Id, const Point Position, const std::string cheminData);

    /**@brief Destructeur de Tower
    @param none
    @return none
    @code
    ~Tower();
    @endcode
    */
	~Tower();

    /**@brief Accesseur du type de tour
    @param none
    @return unsigned int
    @code
    unsigned int getType() const;
    @endcode
    */
	unsigned int getType() const;

    /**@brief Accesseur aux Points d'Attaque
    @param none
    @return unsigned int
    @code
    unsigned int getPA() const;
    @endcode
    */
	unsigned int getPA() const;

    /**@brief Accesseur du niveau de la Tour
    @param none
    @return unsigned int
    @code
    unsigned int getLevel() const;
    @endcode
    */
	unsigned int getLevel() const;

    /**@brief Accesseur du prix d'amélioration de la Tour
    @param none
    @return unsigned int
    @code
    uint getPrixUpgrade() const;
    @endcode
    */
	uint getPrixUpgrade() const;

    /**@brief Accesseur de la zone d'Attaque
    @param none
    @return int
    @code
    int getZone() const;
    @endcode
    */
	int getZone() const;

	/**@brief Accesseur des coordonnées de la Tour
    @param none
    @return [Coord] de type Point
    @code
    Point getCoord() const;
    @endcode
    */
	Point getCoord() const;

    /**@brief Accesseur du nombre d'Ennemis tués par cette Tour
    @param none
    @return unsigned int
    @code
    unsigned int getNbTues() const;
    @endcode
    */
	unsigned int getNbTues() const;

    /**@brief Accesseur du nombre d'Ennemis tués pour level par cette Tour
    @param none
    @return unsigned int
    @code
    unsigned int getNbTuesUpgrade() const;
    @endcode
    */
	unsigned int getNbTuesUpgrade() const;

    /**@brief Accesseur de la Vitesse d'Attaque
    @param none
    @return int
    @code
    int getVA() const;
    @endcode
    */
	int getVA() const;

    /**@brief Accesseur au timeur de recharge de la Tour
    @param none
    @return unsigned int
    @code
    unsigned int getTime() const;
    @endcode
    */
	unsigned int getTime() const;


	/**@brief Accesseur de la zone en cercle d'attaque
    @param none
    @return sf::RectangleShape (librairie SFML)
    @code
    sf::RectangleShape getRectangle() const;
    @endcode
    */
	sf::RectangleShape getRectangle() const;

    /**@brief Mutateur des Points d'Attaque
    @param [nPA] de type const unsigned int
    @return none
    @code
    void setPA(const unsigned int nPA);
    @endcode
    */
	void setPA(const unsigned int nPA);

    /**@brief Mutateur du type de tour
    @param [nType] de type const unsigned int
    @return none
    @code
    void setType(const unsigned int nType);
    @endcode
    */
	void setType(const unsigned int nType);

    /**@brief Mutateur de la Vitesse d'Attaque
    @param [nVA] de type const int
    @return none
    @code
    void setVA(const int nVA);
    @endcode
    */
	void setVA(const int nVA);

    /**@brief Mutateur de la zone d'Attaque
    @param [nZone] de type const int
    @return none
    @code
    void setZone(const int nZone);
    @endcode
    */
	void setZone(const int nZone);

    /**@brief Mutateur du prix d'amélioration de la Tour
    @param [newPrixUpgrade] de type unsigned int
    @return none
    @code
    void setPrixUpgrade(uint newPrixUpgrade);
    @endcode
    */
	void setPrixUpgrade(uint newPrixUpgrade);

    /**@brief Mutateur du niveau de la Tour
    @param [nlevel] de type const unsigned int
    @return none
    @code
    void setLevel(const uint nlevel);
    @endcode
    */
	void setLevel(const uint nlevel);

    /**@brief Redemarre le timeur
    @param none
    @return none
    @code
    void setTime();
    @endcode
    */
    void setTime();

    /**@brief Mutateur du nombre d'Ennemis tués par cette Tour
    @param [nNbTues] de type const unsigned int
    @return none
    @code
    void setNbTues(const unsigned int nNbTues);
    @endcode
    */
	void setNbTues(const unsigned int nNbTues);

    /**@brief Mutateur de la zone de la Tour
    @param none
    @return none
    @code
    void setRectangleEffet();
    @endcode
    */
	void setRectangleEffet();


	/**@brief Augmentation d'un niveau de la Tour
    @param none
    @return none
    @code
    void levelUp();
    @endcode
    */
    void levelUp();

private:

	std::string chemin;
    uint ID, PA, NbTues,level, PrixUpgrade, NbTuesUpgrade, Type;
    int VA;
	int Zone;
    Point Coord;
    sf::RectangleShape RectangleEffet;
    sf::Clock tempsRecharge;

};

#endif
