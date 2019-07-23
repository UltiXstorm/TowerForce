#include "Jeu.h"

////////////////////////////////////////////////////////////////////////////////////////
//                          Constructeurs et Destructeur                              //
////////////////////////////////////////////////////////////////////////////////////////

Jeu::Jeu(const std::string cheminData) {
    //Détermination du chemin de base
    chemin = cheminData + "../data/sprites/";

    //Initialisation des paramètres de base
    Niveau = 1;
    PO = 115;
    Vie = 20;
    NbVague = 1;
    NumVague = 0;
    NbEnnemis = 0;

    chargerMatrice(Niveau);
}

Jeu::~Jeu() {
    //Suppression de tous les pointeurs sur Ennemi dans le vecteur
    while (! lEnnemis.empty())
    {
        pEnnemi = lEnnemis.back();  // Récupère le dernier élement de la liste de vector
        delete pEnnemi;
        lEnnemis.pop_back();         // Détruit le dernier élement de la liste de vector
    }

    //Suppression de tous les pointeurs sur Tower dans le vecteur
    while (! lTowers.empty())
    {
        pTower = lTowers.back();  // Récupère le dernier élement de la liste de vector
        delete pTower;
        lTowers.pop_back();         // Détruit le dernier élement de la liste de vector
    }
}

////////////////////////////////////////////////////////////////////////////////////////
//                                      Accesseurs                                    //
////////////////////////////////////////////////////////////////////////////////////////

int Jeu::getPO() const {
	return PO;
}

uint Jeu::getNbEnnemis() const {
	return NbEnnemis;
}

uint Jeu::getNbVague() const {
	return NbVague;
}

uint Jeu::getNumVague() const {
    return NumVague;
}

int Jeu::getVie() const {
    if (Vie < 0)
        return 0;

    return Vie;
}

sf::Sprite Jeu::getEnnemi(const uint Id) const {
    //Récupère l'élément [Id] de la liste de vector
    return lEnnemis.at(Id)->getSprite();
}

Tower* Jeu::getTower(const Point Case) const {
    //On boucle sur toutes les tours
    for(auto &t : lTowers)
    {
        if(t->getCoord().getX() == Case.getX() && t->getCoord().getY() == Case.getY())
        {
            return t;
        }
    }

    return NULL;
}

uint Jeu::getNiveau() const {
    return Niveau;
}

////////////////////////////////////////////////////////////////////////////////////////
//                                      Mutateurs                                     //
////////////////////////////////////////////////////////////////////////////////////////

void Jeu::setNumVague(const uint NvNum) {
	NumVague=NvNum;
}

void Jeu::setPO(const uint NvPO) {
	PO=NvPO;
}

////////////////////////////////////////////////////////////////////////////////////////
//                                  Autres fonctions                                  //
////////////////////////////////////////////////////////////////////////////////////////

int Jeu::getInMatrice(uint i, uint j) const {
    return Matrice[i][j];
}

void Jeu::bougerEnnemis() {
    //On boucle sur tous les ennemis pour les faire bouger
    for (uint i=0; i<lEnnemis.size(); i++)
    {
        pEnnemi = lEnnemis.at(i);
        bouge(pEnnemi);
    }
}

void Jeu::poserTower(Point Coord) {
    //Si la case est bien dans la matrice
    if(((Coord.getX() > -1) && (Coord.getX() < 20)) && ((Coord.getY() >= 0) && (Coord.getY() < 15)))
    {
        //Si la case est bien du sol
        if(Matrice[Coord.getY()][Coord.getX()] == SOL)
            AjouterTower(Coord);
    }
}

void Jeu::afficherVague(sf::RenderWindow &fenetre) {
    //Affichage de tous les ennemis
     for(auto &e : lEnnemis)
        e->afficherEnnemi(fenetre);
}

void Jeu::afficheZoneTower(sf::RenderWindow &fenetre) {
	//On boucle sur toutes les tours
    for(auto &t : lTowers)
		fenetre.draw(t->getRectangle());
}

void Jeu::tir(sf::RenderWindow &fenetre) {
	//On boucle sur toutes les Tours
    for(uint j=0; j<lTowers.size(); j++)
    {
        Tower *t = lTowers.at(j);

		//On boucle sur tous les ennemis
        for(uint i=0; i<lEnnemis.size(); i++) {
			Ennemi * e = lEnnemis.at(i);

            //Si l'ennemi est a portée de tir
            if(aPortee(e,t))
            {
                int multioudivi = t->getVA();
                uint reloadTimeTower;

                //Si Multioudivi est negatif, une attaque toute les X secondes
                if(multioudivi < 0)
                {
                    multioudivi = multioudivi * -1;
                    reloadTimeTower = 1000*multioudivi;
                }
                //sinon X attaques par seconde
                else
                {
                    reloadTimeTower = 1000/multioudivi;
                }

                multioudivi = multioudivi * -1;

                //Si le temps de recharge de la tour est bon alors on tire
                if(t->getTime() > reloadTimeTower)
                {
                    //La tour tire
                    feu(fenetre,e,t);
                    int butin = e->recoitDegats(t->getPA());

                    //Si le monstre est mort
                    if( butin != 0)
                    {
                        SuppEnnemi(e);
                        t->setNbTues(t->getNbTues()+1);

                        PO = PO + butin;
                    }

                    t->setTime();
                }
            }
        }
    }
}

void Jeu::feu(sf::RenderWindow &fenetre, Ennemi *e, Tower *t) {
    double abscis = ((e->getSprite().getPosition().x / TAILLE_SPRITE) - t->getCoord().getX()) / 10.0;
    double ordon = ((((e->getSprite().getPosition().y)-MENUHAUT)/TAILLE_SPRITE) - (t->getCoord().getY()))/10.0;

    double x = t->getCoord().getX() + 0.5;
    double y = t->getCoord().getY() + 0.5;

    for (uint i=0; i<10; i++)
    {
        x += abscis;
        y += ordon;
        afficherTir(fenetre, x, y);
    }
}

void Jeu::afficherTir(sf::RenderWindow &fenetre, double x, double y) {
    //Affichage des cercles composants un tir
    sf::CircleShape shape(3);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(sf::Vector2f(static_cast<float>(x*TAILLE_SPRITE), static_cast<float>(y*TAILLE_SPRITE+MENUHAUT)));
    fenetre.draw(shape);
}

void Jeu::transformationTower(const Point Case, const uint Choix) {
    //Transformation de la tour en tour spécifique
    pTower = getTower(Case);
    pTower-> setType(Choix);
    PO -= pTower->getPrixUpgrade();
    pTower->levelUp();
    Matrice[Case.getY()][Case.getX()] = T_SNIPER+Choix;
}

bool Jeu::creerVague() {

    PointDebParcours.setX(0);
    NumVague = NumVague+1;

    //Si toutes les vagues sont terminées on change de niveau
    if(NumVague>NbVague)
    {
        if(changerNiveau())
            return true;
    }

    else
    {
        std::string mesVagues, mot;
        mesVagues = chemin + "../vagues/niveau" + std::to_string(Niveau) + ".txt";
        std::ifstream Vague(mesVagues);
        uint NbEnnemisParType;

        if(!Vague.is_open())
        {
            std::cout << "Erreur de chargement de la vague" << std::endl;
            exit(EXIT_FAILURE);
        }
        Vague >> NbVague;


        for(uint i=1; i<=NumVague; i++)
        {
            if(i==NumVague)
            {
                //Initialisation de l'identifiant des monstres
                int idMob = 0;

                //Lecture du nombre dans le fichier txt
                Vague >> NbEnnemisParType;
                NbEnnemis = NbEnnemis + NbEnnemisParType;

                //Création du type d'ennemi
                for(uint i=0; i<NbEnnemisParType; i++)
                {
                    pEnnemi = new Ennemi(idMob, DRAGON, PointDebParcours, chemin, NumVague);
                    lEnnemis.push_back(pEnnemi);    // Insertion en fin de la liste de vectors

                    PointDebParcours.setX(PointDebParcours.getX() - 2);
                    idMob++;
                }

                Vague >> NbEnnemisParType;
                NbEnnemis = NbEnnemis + NbEnnemisParType;
                for(uint i=0; i<NbEnnemisParType; i++)
                {
                    pEnnemi = new Ennemi(idMob, SQUELETTE, PointDebParcours, chemin, NumVague);
                    lEnnemis.push_back(pEnnemi);    // Insertion en fin de la liste de vectors

                    PointDebParcours.setX(PointDebParcours.getX() - 2);
                    idMob++;
                }

                Vague >> NbEnnemisParType;
                NbEnnemis = NbEnnemis + NbEnnemisParType;
                for(uint i=0; i<NbEnnemisParType; i++)
                {
                    pEnnemi = new Ennemi(idMob, SQUELETTE_CHAPEAU, PointDebParcours, chemin, NumVague);
                    lEnnemis.push_back(pEnnemi);    // Insertion en fin de la liste de vectors

                    PointDebParcours.setX(PointDebParcours.getX() - 2);
                    idMob++;
                }

                Vague >> NbEnnemisParType;
                NbEnnemis = NbEnnemis + NbEnnemisParType;
                for(uint i=0; i<NbEnnemisParType; i++)
                {
                    pEnnemi = new Ennemi(idMob, SLIME, PointDebParcours, chemin, NumVague);
                    lEnnemis.push_back(pEnnemi);    // Insertion en fin de la liste de vectors

                    PointDebParcours.setX(PointDebParcours.getX() - 2);
                    idMob++;
                }

                Vague >> NbEnnemisParType;
                NbEnnemis = NbEnnemis + NbEnnemisParType;
                for(uint i=0; i<NbEnnemisParType; i++)
                {
                    pEnnemi = new Ennemi(idMob, PLANTE_CARNIVORE, PointDebParcours, chemin, NumVague);
                    lEnnemis.push_back(pEnnemi);    // Insertion en fin de la liste de vectors

                    PointDebParcours.setX(PointDebParcours.getX() - 2);
                    idMob++;
                }

                Vague >> NbEnnemisParType;
                NbEnnemis = NbEnnemis + NbEnnemisParType;
                for(uint i=0; i<NbEnnemisParType; i++)
                {
                    pEnnemi = new Ennemi(idMob, DRACAUFEU, PointDebParcours, chemin, NumVague);
                    lEnnemis.push_back(pEnnemi);    // Insertion en fin de la liste de vectors

                    PointDebParcours.setX(PointDebParcours.getX() - 2);
                    idMob++;
                }

                Vague >> NbEnnemisParType;
                NbEnnemis = NbEnnemis + NbEnnemisParType;
                for(uint i=0; i<NbEnnemisParType; i++)
                {
                    pEnnemi = new Ennemi(idMob, DEMON, PointDebParcours, chemin, NumVague);
                    lEnnemis.push_back(pEnnemi);    // Insertion en fin de la liste de vectors

                    PointDebParcours.setX(PointDebParcours.getX() - 2);
                    idMob++;
                }

                Vague >> NbEnnemisParType;
                NbEnnemis = NbEnnemis + NbEnnemisParType;
                for(uint i=0; i<NbEnnemisParType; i++)
                {
                    pEnnemi = new Ennemi(idMob, DETRAQUEUR, PointDebParcours, chemin, NumVague);
                    lEnnemis.push_back(pEnnemi);    // Insertion en fin de la liste de vectors

                    PointDebParcours.setX(PointDebParcours.getX() - 2);
                    idMob++;
                }
            }
            else
            {
                for(uint j=0;j<8;j++)
                    Vague >> NbEnnemisParType;
            }

        }

    }
    return false;
}

void Jeu::tourUpgradable(sf::RenderWindow &fenetre, sf::Sprite spriteUp) {
	sf::Sprite Up;

    //On boucle sur les tours
    for(auto &t : lTowers)
    {
        //Si le joueur a assez de PO et d'ennemis tués avec la tour alors affichage d'un indicateur
        if(t->getNbTues()>=t->getNbTuesUpgrade() && PO >= t->getPrixUpgrade())
        {
            spriteUp.setPosition(sf::Vector2f(static_cast<float>(t->getCoord().getX()*32), static_cast<float>((t->getCoord().getY()*32)+64)));
            fenetre.draw(spriteUp);
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////
//                               Autres fonctions Privées                             //
////////////////////////////////////////////////////////////////////////////////////////

void Jeu::chargerMatrice(const uint NumNiveau) {
    std::string monNiveau, mot;

    monNiveau = chemin + "../niveaux/niveau" + std::to_string(NumNiveau) + ".txt";

    std::ifstream Niveau(monNiveau);

    if(!Niveau.is_open())
    {
        std::cout << "Erreur de chargement du Niveau" << std::endl;
        exit(EXIT_FAILURE);
    }

    //Initialisation du point de depart du parcours.
    Niveau >> mot;
    PointDebParcours.setX(atoi(mot.c_str()));
    Niveau >> mot;
    PointDebParcours.setY(atoi(mot.c_str()));

    creerVague();

    //Initialisation de la matrice pour la map
    for(uint i=0; i<HAUTEURMAP; i++)
        for(uint j=0; j<LARGEURMAP; j++)
            Niveau >> Matrice[i][j];

    Niveau.close();

}

void Jeu::AjouterTower(const Point Position) {
	//Si le joueur a assez de PO il pose une nouvelle tour
    if(getPO()>=TOWERPRICE)
    {
    	Matrice[Position.getY()][Position.getX()] = TOWER;

   		pTower = new Tower(static_cast<uint>(lTowers.size()), Position, chemin);
    	lTowers.push_back(pTower);
    	setPO(getPO()-TOWERPRICE);
	}
}

bool Jeu::testDroite(Ennemi *mob, const int posX, const int posY) {

    //Si le sprite de l'ennemi a une route a sa droite alors il bouge
    if(Matrice[posY][posX+1] == R1 || Matrice[posY][posX+1] == R2 || Matrice[posY][posX+1] == R3 || Matrice[posY][posX+1] == R4 || Matrice[posY][posX+1] == R5 || Matrice[posY][posX+1] == R6 || Matrice[posY][posX+1] == FIN)
    {
        mob->setAnimY(Right);

        if(mob->getAnim().x == 2)
            mob->setAnimX(0);
        else if(mob->getAnim().x == 1)
            mob->setAnimX(2);
        else
            mob->setAnimX(1);

        mob->changerPosition(1,0);
        return true;
    }
    return false;

}

bool Jeu::testGauche(Ennemi *mob, const int posX, const int posY) {

    //Si le sprite de l'ennemi a une route a sa gauche alors il bouge
    if(Matrice[posY][posX-1] == R1 || Matrice[posY][posX-1] == R2 || Matrice[posY][posX-1] == R3 || Matrice[posY][posX-1] == R4 || Matrice[posY][posX-1] == R5 || Matrice[posY][posX-1] == R6 || Matrice[posY][posX-1] == FIN)
    {
        mob->setAnimY(Left);

        if(mob->getAnim().x == 2)
            mob->setAnimX(0);
        else if(mob->getAnim().x == 1)
            mob->setAnimX(2);
        else
            mob->setAnimX(1);

        mob->changerPosition(-1,0);
        return true;
    }
    return false;

}

bool Jeu::testHaut(Ennemi *mob, const int posX, const int posY) {

    //Si le sprite de l'ennemi a une route en haut alors il bouge
    if(Matrice[posY-1][posX] == R1 || Matrice[posY-1][posX] == R2 || Matrice[posY-1][posX] == R3 || Matrice[posY-1][posX] == R4 || Matrice[posY-1][posX] == R5 || Matrice[posY-1][posX] == R6 ||  Matrice[posY-1][posX] == FIN)
    {
        mob->setAnimY(Up);

        if(mob->getAnim().x == 2)
            mob->setAnimX(0);
        else if(mob->getAnim().x == 1)
            mob->setAnimX(2);
        else
            mob->setAnimX(1);

        mob->changerPosition(0,-1);
        return true;
    }
    return false;

}

bool Jeu::testBas(Ennemi *mob, const int posX, const int posY) {

    //Si le sprite de l'ennemi vers le bas a sa droite alors il bouge
    if(Matrice[posY+1][posX] == R1 ||  Matrice[posY+1][posX] == R2 || Matrice[posY+1][posX] == R3 || Matrice[posY+1][posX] == R4 || Matrice[posY+1][posX] == R5 || Matrice[posY+1][posX] == R6 ||  Matrice[posY+1][posX] == FIN)
    {
        mob->setAnimY(Down);

        if(mob->getAnim().x == 2)
            mob->setAnimX(0);
        else if(mob->getAnim().x == 1)
            mob->setAnimX(2);
        else
            mob->setAnimX(1);

        mob->changerPosition(0,1);
        return true;
    }
    return false;
}

void Jeu::bouge(Ennemi *mob) {
    //Récupération des coordonnées de l'ennemi
    int positionX = mob->getCoord().getX();
    int positionY = mob->getCoord().getY();

    //Si l'Ennemi est en dehors de l'ecran : on le supprime
    if(positionX > 19)
    {
        //On enlève au joueur la vie correspondant a la capacité du monstre        
        Vie -= mob->getVolVie(); 
        SuppEnnemi(mob);
    }

    //Si l'Ennemi est en dehors de la carte vers la gauche (il n'est pas encore entré) alors on le fait avancer vers la droite
    //Ou si l'Ennemi est sur la case de fin alors il avance vers la droite jusqu'à sortir de l'écran
    if (positionX < 0 || Matrice[positionY][positionX] == FIN)
    {
        mob->setAnimY(Right);

        if(mob->getAnim().x == 2)
            mob->setAnimX(0);
        else if(mob->getAnim().x == 1)
            mob->setAnimX(2);
        else
            mob->setAnimX(1);

        mob->changerPosition(1,0);
        return;
    }

    //Test dans des sens différents suivant l'orientation actuelle de l'ennemi sur la carte
    //Le test de l'inverse doit toujours être effectué en dernier
    switch(mob->getAnim().y)
    {
        case Down:
            if(testBas(mob, positionX, positionY))
                break;
            else if(testDroite(mob, positionX, positionY))
                break;
            else if(testGauche(mob, positionX, positionY))
                break;
            else if(testHaut(mob, positionX, positionY))
                break;
        case Left:
            if(testGauche(mob, positionX, positionY))
                break;
            else if(testBas(mob, positionX, positionY))
                break;
            else if(testHaut(mob, positionX, positionY))
                break;
            else if(testDroite(mob, positionX, positionY))
                break;
        case Right:
            if(testDroite(mob, positionX, positionY))
                break;
            else if(testBas(mob, positionX, positionY))
                break;
            else if(testHaut(mob, positionX, positionY))
                break;
            else if(testGauche(mob, positionX, positionY))
                break;
        case Up:
            if(testHaut(mob, positionX, positionY))
                break;
            else if(testDroite(mob, positionX, positionY))
                break;
            else if(testGauche(mob, positionX, positionY))
                break;
            else if(testBas(mob, positionX, positionY))
                break;
    }
}

bool Jeu::aPortee (const Ennemi *mob, const Tower *tower) {
	//Si le monstre est dans la zone carré de la tour alors il est a portée
    if (((mob->getCoord().getX()>=tower->getCoord().getX()-tower->getZone()) && (mob->getCoord().getX()<=tower->getCoord().getX()+tower->getZone())) &&
		 ((mob->getCoord().getY()>=tower->getCoord().getY()-tower->getZone()) && (mob->getCoord().getY()<=tower->getCoord().getY()+tower->getZone())))
		return true;
	else
		return false;
}

void Jeu::SuppEnnemi (Ennemi *mob) {
    //On boucle sur les ennemis
    for(uint i=0; i<lEnnemis.size(); i++)
    {
        pEnnemi = lEnnemis.at(i);
        //Quand on trouve l'ennemi recherché on le supprime
        if(pEnnemi->getID() == mob->getID())
        {
            lEnnemis.erase(lEnnemis.cbegin() + i);
            delete mob;
            NbEnnemis--;
            break;
        }
    }
}

bool Jeu::changerNiveau() {
    //Réinitialisation des paramètres de base
    Niveau++;
    NumVague=0;
    Vie=20;
    PO=150+Niveau*25;

    //Si on a passé les 3 niveaux alors on a terminé le jeu
    if(Niveau > 3)
        return true;

    else
    {
        //Suppression des tours du niveau précédent
        while(!lTowers.empty())
        {
            pTower = lTowers.back();
            delete pTower;
            lTowers.pop_back();
        }

        chargerMatrice(Niveau);
        return false;
    }
}

