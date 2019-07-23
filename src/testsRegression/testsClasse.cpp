//FICHIER DE TESTS DE REGRESSION

#include "../core/Ennemi.h"
#include "../core/Tower.h"

int main()
{
    //----------------------------------------------------------TEST DE LA CLASSE POINT---------------------------------------------------------------
    Point Point1;
    Point Point2(5, 8);

    //Vérification constructeurs + Vérification des Get
    if(Point1.getX() == 0 && Point1.getY() == 0)
        std::cout << "Constructeur par défaut ok !" << std::endl;
    else
        std::cout << "Constructeur par défaut Nope !" << std::endl;

    if(Point2.getX() == 5 && Point2.getY() == 8)
        std::cout << "Constructeur par copie ok !" << std::endl;
    else
        std::cout << "Constructeur par copie Nope ! X = " << Point2.getX() << " et Y = " << Point2.getY() << std::endl;

    //Vérification des Set
    Point1.setX(10);
    Point1.setY(50);

    std::cout << "Point1 a un x de : " << Point1.getX() << " et un y de : " << Point1.getY() << std::endl;

    //----------------------------------------------------------TEST DE LA CLASSE ENNEMI--------------------------------------------------------------
    Ennemi E1;
    Ennemi E2(2, 2, Point2);

    //Vérification constructeurs + Vérifications Get
    if(E1.getLoot() == 5 && E1.getPV() == 10)
        std::cout << "Constructeur par défaut ok !" << std::endl;
    else
        std::cout << "Constructeur par défaut Nope !" << std::endl;

    std::cout << "Pour E2 Loot = " << E2.getLoot() << " et PV = " << E2.getPV() << std::endl;

    //----------------------------------------------------------TEST DE LA CLASSE TOWER---------------------------------------------------------------

    return 0;
}