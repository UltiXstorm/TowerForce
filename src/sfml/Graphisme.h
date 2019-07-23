/**
    @brief classe Graphisme
	gère les graphisme du jeu
	@author p1508644
	@file Graphisme.h
	@version 2.3
	@date 2018/02/27
*/

#ifndef Graphisme_H_INCLUDED
#define Graphisme_H_INCLUDED

#include "../core/Jeu.h"
#include "./Bouton.h"
#include "./Message.h"

/**
    @brief Class Graphisme

    Cette classe permet de gérer les graphismes du jeu.
*/


class Graphisme
{
    public:

    sf::RenderWindow fenetre;

    /**@brief Constructeur avec paramètres de Graphisme
    @param none
    @return none
    @code
    Graphisme(const std::string cheminData);
    @endcode
    */
    Graphisme(const std::string cheminData);

    /**@brief Destructeur de Graphisme
    @param none
    @return none
    @code
    ~Ennemi();
    @endcode
    */
    ~Graphisme();

    /**@brief Accesseur du Sprite de fond
    @param none
    @return sf::Sprite (librairie SFML)
    @code
    sf::Sprite getFond() const;
    @endcode
    */
    sf::Sprite getFond() const;

    /**@brief Accesseur du Sprite de la carte
    @param none
    @return sf::Sprite (librairie SFML)
    @code
    sf::Sprite getMap() const;
    @endcode
    */
    sf::Sprite getMap() const;

    /**@brief Accesseur du Sprite de l'image lvlup
    @param none
    @return sf::Sprite (librairie SFML)
    @code
    sf::Sprite getSpriteLvlUp() const;
    @endcode
    */
    sf::Sprite getSpriteLvlUp() const;


    /**@brief Accesseur de la case selectionnée
    @param none
    @return Case de type Point
    @code
    Point getCase() const;
    @endcode
    */
    Point getCase() const;

    /**@brief Accesseur de la musique des tours
    @param none
    @return Music (librairie SFML) par référence
    @code
    sf::Music& getMusiqueTour();
    @endcode
    */
    sf::Music& getMusiqueTour();

    /**@brief Accesseur de la musique principale
    @param none
    @return Music (librairie SFML) par référence
    @code
    sf::Music& getMusiqueMain();
    @endcode
    */
    sf::Music& getMusiqueMain();

    /**@brief Mutateur de la case selectionnée
    @param [tCase] de type Point
    @return none
    @code
    void setCase(Point tCase);
    @endcode
    */
    void setCase(Point tCase);

    /**@brief Mutateur de la texture de map
    @param [Niveau] de type const unsigned int
    @return none
    @code
    void setTextureMap(const uint Niveau);
    @endcode
    */
    void setTextureMap(const uint Niveau);

    /**@brief Accesseur de la case en surbrillance selectionnée
    @param none
    @return sf::Recangleshape (librairie SFML)
    @code
    sf::RectangleShape getcaseSelection() const;
    @endcode
    */
    sf::RectangleShape getcaseSelection() const;

    /**@brief Affiche les statistiques du jeu
    @param [Partie] de type const Jeu passé par référence
    @param [cas] de type const unsigned int (0 si pas précisé)
    @return none
    @code
    void afficheStats(const Jeu &Partie, const uint cas=0);
    @endcode
    */
    void afficheStats(const Jeu &Partie, const uint cas=0);

    /**@brief Gère les événements clavier
    @param [event] de type sf::Event (librairie SFML)
    @return none
    @code
    void eventClavier(sf::Event event);
    @endcode
    */
    void eventClavier(sf::Event event);

    /**@brief Gère les événements souris
    @param [event] de type sf::Event (librairie SFML)
    @param [Partie] de type Jeu en donnée résultat
    @return none
    @code
    void eventSouris(sf::Event event, Jeu Partie);
    @endcode
    */
    void eventSouris(sf::Event event, Jeu &Partie);

    /**@brief Affiche le message de fin de partie ou de fin de vague
    @param [type] de type const unsigned int
    @param [time] de type const unsigned int (0 si pas précisé)
    @return none
    @code
    void afficheMessage(const uint type, uint time=0);
    @endcode
    */
    void afficheMessage(const uint type, uint time=0);

    /**@brief Affiche la matrice à l'écran
    @param [Partie] de type const Jeu passé par référence
    @return none
    @code
    void afficheMatrice(const Jeu &Partie);
    @endcode
    */
    void afficheMatrice(const Jeu &Partie);

    /**@brief Affiche le menu d'achat en bas de l'ecran
    @param [Partie] de type const Jeu passé par référence
    @return none
    @code
    void afficheMenuAchat(const Jeu &Partie);
    @endcode
    */
    void afficheMenuAchat(const Jeu &Partie);

    /**@brief Mettre une case en surbrillance et afficher ses infos dans l'IHM du bas
    @param none
    @return none
    @code
    void surbrillance();
    @endcode
    */
    void surbrillance();

    private:
    std::string chemin;

    sf::Font font;

    sf::Texture tFond;
    sf::Sprite sprite_fond;

    sf::Texture tCarte;
    sf::Sprite sprite_map;

    sf::Texture tLvlUp;
    sf::Sprite sprite_LvlUp;

    sf::Vector2i positionSouris;
    sf::RectangleShape caseSelection;
    Point Case;

    Bouton boutonAchat1;
    Bouton boutonAchat2;
    Bouton boutonAchat3;
    Bouton boutonTourDepart;
    Bouton boutonLvlUp;

    uint typeAchat;

    sf::Music music_main;
    sf::Music music_achat;

    sf::Text StatsTours;

    /**@brief Cache tous les boutons à l'utilisateur
    @param none
    @return none
    @code
    void cacherAllBoutons();
    @endcode
    */
    void cacherAllBoutons();

    /**@brief Affiche les statistiques de la tour selectionnée par le joueur
    @param [Tour] de type pointeur sur Tower
    @return none
    @code
    void afficheStatsTours(const Tower* Tour);
    @endcode
    */
    void afficheStatsTours(const Tower* Tour);
};

#endif


