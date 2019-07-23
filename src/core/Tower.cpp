#include "Tower.h"

//////////////////////////////////////////////////////////////////////////////////////////
//                          Constructeurs et Destructeur								//
//////////////////////////////////////////////////////////////////////////////////////////
Tower::Tower(const uint Id, const Point Position, const std::string cheminData) {
	//Détermination du chemin
    chemin = cheminData + "../data/";

    //Initialisation des paramètres de base
    PA = 4;
	VA = 2;
	Zone = 2;
	Coord.setX(Position.getX());
	Coord.setY(Position.getY());
	NbTues = 0;
	level = 0;
    NbTuesUpgrade = 2;
    PrixUpgrade = 25;

    setRectangleEffet();
	RectangleEffet.setFillColor(sf::Color(0,0,40,35));
}

Tower::~Tower() {

}

//////////////////////////////////////////////////////////////////////////////////////////
//                                      Accesseurs										//
//////////////////////////////////////////////////////////////////////////////////////////

uint Tower::getPA() const {
	return PA;
}

uint Tower::getLevel() const {
	return level;
}

int Tower::getZone() const {
	return Zone;
}

uint Tower::getNbTues() const{
	return NbTues;
}

uint Tower::getType() const{
	return Type;
}

int Tower::getVA() const {
	return VA;
}

uint Tower::getTime() const {
	return tempsRecharge.getElapsedTime().asMilliseconds();
}

sf::RectangleShape Tower::getRectangle() const {
	return RectangleEffet;
}

Point Tower::getCoord() const {
	return Coord;
}

uint Tower::getPrixUpgrade() const{
	return PrixUpgrade;
}

uint Tower::getNbTuesUpgrade() const{
	return NbTuesUpgrade;
}

//////////////////////////////////////////////////////////////////////////////////////////
//                                      Mutateurs										//
//////////////////////////////////////////////////////////////////////////////////////////

void Tower::setPA(const unsigned int nPA) {
	PA=nPA;
}

void Tower::setVA(const int nVA) {
	VA=nVA;
}

void Tower::setType(const uint nType) {
	Type = nType;
}

void Tower::setZone(const int nZone) {
	Zone=nZone;
}

void Tower::setLevel( const uint nlevel) {
	level=nlevel;
}

void Tower::setPrixUpgrade( const uint newPrixUpgrade) {
	PrixUpgrade = newPrixUpgrade;
}

void Tower::setTime() {
	tempsRecharge.restart();
}

void Tower::setNbTues(const uint nNbTues) {
	NbTues=nNbTues;
}

void Tower::setRectangleEffet() {
    sf::Vector2f pos(static_cast<float>((Coord.getX()-Zone)*TAILLE_SPRITE), static_cast<float>((Coord.getY()-Zone)*TAILLE_SPRITE+64));
    RectangleEffet.setPosition(pos);
    RectangleEffet.setSize(sf::Vector2f(static_cast<float>((Zone*TAILLE_SPRITE)*2+32), static_cast<float>((Zone*TAILLE_SPRITE)*2+32)));
}

//////////////////////////////////////////////////////////////////////////////////////////
//                                  Autres fonctions									//
//////////////////////////////////////////////////////////////////////////////////////////
void Tower::levelUp() {
    NbTues = 0;
    level++;

    //Suivant le type spécifique de tour
    switch(Type)
    {
        case SNIPER:

            //Suivant le niveau actuel de la tour
            switch(level)
            {
                case 1:
                    PA = 50;
                    VA = -3;
                    Zone = 4;
                    NbTuesUpgrade = 5;
                    PrixUpgrade = 50;
                    break;

                case 2:
                    PA = 100;
                    VA = -3;
                    Zone = 5;
                    NbTuesUpgrade = 6;
                    PrixUpgrade = 75;
                    break;

                case 3:
                    PA = 150;
                    VA = -3;
                    Zone = 6;
                    NbTuesUpgrade = 7;
                    PrixUpgrade = 100;
                    break;

                case 4:
                    PA = 200;
                    VA = -3;
                    Zone = 6;
                    NbTuesUpgrade = 10;
                    PrixUpgrade = 125;
                    break;

                case 5:
                    PA = 250;
                    VA = -3;
                    Zone = 7;
                    NbTuesUpgrade = 25;
                    PrixUpgrade = 250;
                    break;

                case 6:
                    PA = 300;
                    VA = -2;
                    Zone = 8;
                    NbTuesUpgrade = 40;
                    PrixUpgrade = 400;
                    break;
            }
            break;

        case MITRAILLETTE:
            switch(level)
            {
                case 1:
                    PA = 2;
                    VA = 7;
                    Zone = 1;
                    NbTuesUpgrade = 5;
                    PrixUpgrade = 30;
                    break;

                case 2:
                    PA = 2;
                    VA = 10;
                    Zone = 1;
                    NbTuesUpgrade = 6;
                    PrixUpgrade = 40;
                    break;

                case 3:
                    PA = 2;
                    VA = 12;
                    Zone = 1;
                    NbTuesUpgrade = 7;
                    PrixUpgrade = 50;
                    break;

                case 4:
                    PA = 2;
                    VA = 15;
                    Zone = 1;
                    NbTuesUpgrade = 10;
                    PrixUpgrade = 75;
                    break;

                case 5:
                    PA = 2;
                    VA = 20;
                    Zone = 1;
                    NbTuesUpgrade = 25;
                    PrixUpgrade = 100;
                    break;

                case 6:
                    PA = 3;
                    VA = 20;
                    Zone = 2;
                    NbTuesUpgrade = 40;
                    PrixUpgrade = 200;
                    break;
            }
            break;

        case REX:
            switch(level)
            {
                case 1:
                    PA = 10;
                    VA = 1;
                    Zone = 2;
                    NbTuesUpgrade = 5;
                    PrixUpgrade = 30;
                    break;

                case 2:
                    PA = 15;
                    VA = 1;
                    Zone = 2;
                    NbTuesUpgrade = 6;
                    PrixUpgrade = 40;
                    break;

                case 3:
                    PA = 20;
                    VA = 1;
                    Zone = 2;
                    NbTuesUpgrade = 7;
                    PrixUpgrade = 50;
                    break;

                case 4:
                    PA = 25;
                    VA = 1;
                    Zone = 2;
                    NbTuesUpgrade = 10;
                    PrixUpgrade = 75;
                    break;

                case 5:
                    PA = 30;
                    VA = 1;
                    Zone = 3;
                    NbTuesUpgrade = 25;
                    PrixUpgrade = 100;
                    break;

                case 6:
                    PA = 40;
                    VA = 1;
                    Zone = 3;
                    NbTuesUpgrade = 40;
                    PrixUpgrade = 200;
                    break;
            }
            break;
    }

    //Mise a jour de la portée visuelle de la tour
    setRectangleEffet();
}























