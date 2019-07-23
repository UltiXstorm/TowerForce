/**
    @brief fichier de constantes et d'include
	stocke les constantes et les include
	@author p1508644
	@file Constantes.h
	@version 2.0
	@date 2018/03/12
*/


////////////////////////////////////////////////////////////////////////////////////////
//                            Liste de tous les Include                               //
////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
typedef unsigned int uint;


////////////////////////////////////////////////////////////////////////////////////////
//                            Listes de tous les Define                               //
////////////////////////////////////////////////////////////////////////////////////////

///@brief Nombre de tuiles en hauteur de la map
#define HAUTEURMAP 15

///@brief Nombre de tuiles en largeur de la map
#define LARGEURMAP 20

//@brief Taille en pixels de la hauteur du menu du haut
#define MENUHAUT 64

//@brief Taille en pixels de la hauteur du menu du bas
#define MENUBAS 160

//@brief Hauteur des boutons d'achat
#define HAUTEUR_BOUTON HAUTEUR-32

///@brief Taille de Sprite utilisé
#define TAILLE_SPRITE 32

///@brief Prix d'une tour
#define TOWERPRICE 50

///@brief Hauteur de la fenetre
#define HAUTEUR HAUTEURMAP*TAILLE_SPRITE+MENUHAUT+MENUBAS

//@brief Largeur de la fenetre
#define LARGEUR LARGEURMAP*TAILLE_SPRITE

//@brief Police utilisée
#define FONT "police/emmasophia.ttf"

////////////////////////////////////////////////////////////////////////////////////////
//                            Listes de tous les enums                                //
////////////////////////////////////////////////////////////////////////////////////////

enum terrain{R1, R2, R3, R4, R5, R6, SOL, DECO1, DECO2, DECO3, DECO4, DECO5, DECO6, DECO7, DECO8, DECO9, DECO10, DECO11, TOWER, T_SNIPER, T_MITRAILLETTE, T_REX, DEBUT, FIN};
enum Dir{Down, Left, Right, Up};
enum message{VAGUE, PARTIE, MANCHE, POSER_TOUR, FINI};
enum {SQUELETTE, SQUELETTE_CHAPEAU, DETRAQUEUR, DRAGON, SLIME, PLANTE_CARNIVORE, DRACAUFEU, DEMON};
enum {TOWER1, TOWER2, TOWER3, TOWER4};
enum {RIEN, ACHAT, CHOIX, LVLUP};
enum {SNIPER, MITRAILLETTE, REX};
enum {GAUCHE, CENTRE, DROITE};
