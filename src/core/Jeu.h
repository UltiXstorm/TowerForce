/**
    @brief classe Jeu
	gère les actions relatives au jeu
	@author p1508579, p1507711, p1508644
	@file Jeu.h
	@version 2.0
	@date 2018/03/08
*/

#ifndef Jeu_H_INCLUDED
#define Jeu_H_INCLUDED

#include "Tower.h"
#include "Ennemi.h"

/**
    @brief Class Jeu

    Cette classe permet de gérer les actions relatives au jeu.
*/

class Jeu {

public :

    /**@brief Constructeur avec paramètre de Jeu
	@param [cheminData] de type const string
	@return none
	@code
	Jeu(const std::string cheminData);
	@endcode
	*/
    Jeu(const std::string cheminData);

    /**@brief Destructeur de la classe Jeu
	@param none
	@return none
	@code
	~Jeu();
	@endcode
	*/
    ~Jeu();

    /**@brief Accesseur au nombre de Pièces d'Or
	@param none
	@return int
	@code
	int getPO() const;
	@endcode
	*/
	int getPO() const;

	/**@brief Accesseur au nombre d'ennemis
	@param none
	@return unsigned int
	@code
	uint getNbEnnemis() const;
	@endcode
	*/
	uint getNbEnnemis() const;

	/**@brief Accesseur au nombre de vague dans le niveau
	@param none
	@return unsigned int
	@code
	uint getNbVague() const;
	@endcode
	*/
	uint getNbVague() const;

    /**@brief Accesseur à l'identifiant de la vague
	@param none
	@return unsigned int
	@code
	uint getNumVague() const;
	@endcode
	*/
	uint getNumVague() const;

	/**@brief Accesseur à la vie restante du joueur
	@param none
	@return int
	@code
	int getVie() const;
	@endcode
	*/
	int getVie() const;

	/**@brief Accesseur au sprite d'un Ennemi de la liste
	@param [Id] de type const unsigned int
	@return le sprite d'un Ennemi en particulier
	@code
	sf::Sprite getEnnemi(const uint Id) const;
	@endcode
	*/
	sf::Sprite getEnnemi(const uint Id) const;

    /**@brief Accesseur à une tour en fonction de sa position dans la matrice
	@param [Case] de type const Point
	@return un pointeur sur Tower
	@code
	Tower* getTower(const Point Case) const;
	@endcode
	*/
    Tower* getTower(const Point Case) const;

    /**@brief Accesseur au Niveau en cours
	@param none
	@return unsigned int
	@code
	uint getNiveau() const;
	@endcode
	*/
    uint getNiveau() const;

    /**@brief Mutateur de l'identifiant de la vague
	@param [NvNum] de type const unsigned int
	@return none
	@code
	void setNumVague(const uint NvNum);
	@endcode
	*/
	void setNumVague(const uint NvNum);

	/**@brief Mutateur des Pièces d'Or
	@param [NvPO] de type const unsigned int
	@return none
	@code
	void setPO(const uint NvPO);
	@endcode
	*/
	void setPO(const uint NvPO);

	/**@brief Retourne l'element demandé dans la matrice
    @param [i] de type unsigned int
    @param [j] de type unsigned int
	@return integer
	@code
	int getInMatrice(uint i, uint j) const;
	@endcode
	*/
    int getInMatrice(uint i, uint j) const;

    /**@brief Bouge tous les ennemis
	@param none
	@return none
	@code
	void bougerEnnemis();
	@endcode
	*/
	void bougerEnnemis();

	/**@brief Pose une Tour de defense sur la carte
	@param [Coord] de type Point
	@return none
	@code
	void poserTower(Point Coord);
	@endcode
	*/
	void poserTower(Point Coord);

    /**@brief affiche la vague d'ennemis
	@param [fenetre] de type sf::RenderWindow (librairie SFML) par référence
	@return none
	@code
	void afficherVague(sf::RenderWindow &fenetre);
	@endcode
	*/
	void afficherVague(sf::RenderWindow &fenetre);

	/**@brief Affiche la zone d'attaque des tours
	@param [fenetre] de type sf::RenderWindow (librairie SFML) par référence
	@return none
	@code
	void afficheZoneTower(sf::RenderWindow &fenetre);
	@endcode
	*/
	void afficheZoneTower(sf::RenderWindow &fenetre);

	/**@brief Tir sur les Ennemis à portée
	@param [fenetre] de type sf::RenderWindow (librairie SFML) par référence
	@return none
	@code
	void tir(sf::RenderWindow &fenetre);
	@endcode
	*/
	void tir(sf::RenderWindow &fenetre);

	/**@brief Animation du projectile
	@param [fenetre] de type sf::RenderWindow (librairie SFML) par référence
    @param [e] de type pointeur sur Ennemi
	@param [t] de type pointeur sur Tower
	@return none
	@code
	void feu(sf::RenderWindow &fenetre, Ennemi *e, Tower *t);
	@endcode
	*/
	void feu(sf::RenderWindow &fenetre, Ennemi *e, Tower *t);

	/**@brief affiche le projectile
	@param [fenetre] de type sf::RenderWindow (librairie SFML) par référence
	@param [x] de type double
	@param [y] de type double
	@return none
	@code
	void afficherTir(sf::RenderWindow &fenetre, double x, double y);
	@endcode
	*/
	void afficherTir(sf::RenderWindow &fenetre, double x, double y);

    /**@brief Améliore spécifiquement la tour visée
	@param [Case] de type const Point
	@param [Choix] de type const unsigned int
	@return none
	@code
	void transformationTower(const Point Case, const uint Choix);
	@endcode
	*/
	void transformationTower(const Point Case, const uint Choix);

	/**@brief Créer une vague d'ennemis
	@param none
	@return bool
	@code
	void creerVague();
	@endcode
	*/
	bool creerVague();

	/**@brief Affiche une image sur la tour si la tour peut être amélioré
    @param [fenetre] de type sf::RenderWindow (librairie SFML) par référence
	@param [spriteUp] de type sf::Sprite (librairie SFML)
    @return none
    @code
    void tourUpgradable(sf::RenderWindow &fenetre, sf::Sprite spriteUp);
    @endcode
    */
    void tourUpgradable(sf::RenderWindow &fenetre, sf::Sprite spriteUp);


private :

    std::string chemin;

    int Matrice[HAUTEURMAP][LARGEURMAP];

	uint Niveau, NumVague, NbEnnemis, PO, NbVague;
    int Vie;

	Point PointDebParcours;

	std::vector <Ennemi *> lEnnemis;
	Ennemi *pEnnemi;

	std::vector <Tower *> lTowers;
	Tower *pTower;

	/**@brief charge la matrice d'un niveau
	@param [Niveau] de type unsigned int
	@return none
	@code
	void chargerMatrice(const uint Niveau);
	@endcode
	*/
	void chargerMatrice(const uint Niveau);

	/**@brief Ajoute une Tour dans le vecteur
	@param [Coord] de type const Point
	@return none
	@code
	void AjouterTower(const Point Coord);
	@endcode
	*/
	void AjouterTower(const Point Coord);

	/**@brief Teste si un ennemi va à droite
	@param [mob] de type pointeur sur Ennemi
    @param [posX] de type const integer
    @param [posY] de type const integer
	@return booléan
	@code
	bool testDroite(Ennemi *mob, const int posX, const int posY);
	@endcode
	*/
	bool testDroite(Ennemi *mob, const int posX, const int posY);

	/**@brief Teste si un ennemi va à gauche
	@param [mob] de type pointeur sur Ennemi
    @param [posX] de type const integer
    @param [posY] de type const integer
	@return booléan
	@code
	bool testGauche(Ennemi *mob, const int posX, const int posY);
	@endcode
	*/
	bool testGauche(Ennemi *mob, const int posX, const int posY);

	/**@brief Teste si un ennemi va en haut
	@param [mob] de type pointeur sur Ennemi
    @param [posX] de type const integer
    @param [posY] de type const integer
	@return booléan
	@code
	bool testHaut(Ennemi *mob, const int posX, const int posY);
	@endcode
	*/
	bool testHaut(Ennemi *mob, const int posX, const int posY);

	/**@brief Teste si un ennemi va en bas
	@param [mob] de type pointeur sur Ennemi
    @param [posX] de type const integer
    @param [posY] de type const integer
	@return booléan
	@code
	bool testBas(Ennemi *mob, const int posX, const int posY);
	@endcode
	*/
	bool testBas(Ennemi *mob, const int posX, const int posY);

	/**@brief Fait bouger un ennemi en suivant le chemin ou s'il est trop haut il descend en ligne droite
    @param [mob] de type pointeur sur Ennemi
    @return un booléan
    @code
    void bouge(Ennemi *mob);
    @endcode
    */
    void bouge(Ennemi *mob);

    /**@brief Teste si l'Ennemi est à portée de la Tour
	@param [mob] de type pointeur sur Ennemi
	@param [tower] de type pointeur sur Tower
	@return booléan
	@code
	bool aPortee (const Ennemi *mob, const Tower *tower);
	@endcode
	*/
	bool aPortee (const Ennemi *mob, const Tower *tower);

    /**@brief Supprime un Ennemi de la liste de vecteur lEnnemis
	@param [mob] de type pointeur sur Ennemi
    @param [ID] de type const unsigned int (paramètre par défaut = 0)
	@return none
	@code
	void SuppEnnemi (Ennemi *mob, const uint ID = 0);
	@endcode
	*/
	void SuppEnnemi (Ennemi *mob);

    /**@brief change le niveau de jeu (map et vagues)
	@param none
	@return none
	@code
	bool changerVague();
	@endcode
	*/
	bool changerNiveau();


};

#endif
