#include "sfml/Graphisme.h"
#include "core/Jeu.h"

int main(int argc, char *argv[])
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                                                  INITIALISATION DES DIFFÉRENTES VARIABLES                                               //
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::string pathExec = argv[0];
    //Recherche le dernier / ou \ (delimiteur de répertoire sous linux ou windows)
    std::size_t found = pathExec.find_last_of("/\\");
    //On ne garde que le chemin de l'executable (avec le / ou \)
    pathExec = pathExec.substr(0, found + 1);

    ////////////////////////////////////////////////////////////////////////////////////////
    //              Initialisation d'une fenetre avec la classe Graphisme                 //
    ////////////////////////////////////////////////////////////////////////////////////////
    Graphisme Affichage (pathExec);
    sf::Sprite Sfond = Affichage.getFond();

    ////////////////////////////////////////////////////////////////////////////////////////
    //                             Initialisation de la Partie                            //
    ////////////////////////////////////////////////////////////////////////////////////////
    Jeu Partie (pathExec);
    sf::Clock timeur;
    sf::Clock timeVague;
    sf::Clock timeDebut;
    uint temp;
    bool DebutNiveau = true;
    bool Fin = false;

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                                                  GESTION DE LA PARTIE                                                                   //
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////
    //                          Tant que la fenetre de jeu est ouverte                    //
    ////////////////////////////////////////////////////////////////////////////////////////
    while (Affichage.fenetre.isOpen())
    {

        //Affichage précédent effacé
        Affichage.fenetre.clear();

        //Variable de type evenement
        sf::Event event;

        //Boucle d'évenements
        while (Affichage.fenetre.pollEvent(event))
        {
            //Gestion des événements clavier
            Affichage.eventClavier(event);

            //Gestion des événements souris
            Affichage.eventSouris(event,Partie);
        }

        //Affichage du fond
        Affichage.fenetre.draw(Sfond);

        //Affichage de la carte de jeu
        Affichage.afficheMatrice(Partie);

        //Affichage des tour potentiellement améliorable
        Partie.tourUpgradable(Affichage.fenetre,Affichage.getSpriteLvlUp());

        //Affichage du menu d'achat
        Affichage.afficheMenuAchat(Partie);



        ////////////////////////////////////////////////////////////////////////////////////////
        //                          Vérification si le jeu continu                            //
        ////////////////////////////////////////////////////////////////////////////////////////
        if(Fin)
            Affichage.afficheMessage(FINI);

        else
        {
            ////////////////////////////////////////////////////////////////////////////////////////
            //                          Mise en place des premières Tours                         //
            ////////////////////////////////////////////////////////////////////////////////////////
            if(DebutNiveau == true)
            {
                temp = static_cast<uint>(timeDebut.getElapsedTime().asSeconds());
                if (temp <= 15)
                {
                    Affichage.afficheMessage(POSER_TOUR, temp);
                    Affichage.afficheStats(Partie, 3);
                }
                else
                    DebutNiveau = false;

            }

            ////////////////////////////////////////////////////////////////////////////////////////
            //                     Après le placement des premières Tours                         //
            ////////////////////////////////////////////////////////////////////////////////////////
            else
            {
                //Affichage des Statistiques
                Affichage.afficheStats(Partie);

                ///////////////////////////////////////////////////////////////////////////////////////////
                //                         Si le joueur n'a pas perdu la partie                          //
                ///////////////////////////////////////////////////////////////////////////////////////////
                if(Partie.getVie() > 0)
                {
                    ////////////////////////////////////////////////////////////////////////////////////////
                    //                         Si la vague n'est pas terminée                             //
                    ////////////////////////////////////////////////////////////////////////////////////////
                    if(Partie.getNbEnnemis() != 0)
                    {
                        //Timeur pour les actions automatiques (déplacements des Ennemis)
                        uint nt = timeur.getElapsedTime().asMilliseconds();
                        if (nt>40)
                        {
                            Partie.bougerEnnemis();
                            timeur.restart();
                        }

                        Partie.tir(Affichage.fenetre);
                        Partie.afficherVague(Affichage.fenetre);
                        timeVague.restart();
                    }

                    ////////////////////////////////////////////////////////////////////////////////////////
                    //                          Si la vague est terminée                                  //
                    ////////////////////////////////////////////////////////////////////////////////////////
                    else
                    {

                        temp = static_cast<uint>(timeVague.getElapsedTime().asSeconds());

                        //Si on doit passer à la manche superieure
                        if(Partie.getNumVague()==Partie.getNbVague())
                        {
                            if (temp>=5)
                            {
                                DebutNiveau = true;
                                Fin = Partie.creerVague();
                                Affichage.setTextureMap(Partie.getNiveau());
                                timeDebut.restart();
                            }
                            else
                                Affichage.afficheMessage(MANCHE, temp);
                        }

                        //On doit passer à la vague suivante
                        else
                        {
                            if (temp>=5)
                            {
                                Fin = Partie.creerVague();
                                Affichage.setTextureMap(Partie.getNiveau());
                            }
                            else
                                Affichage.afficheMessage(VAGUE, temp);
                        }

                    }

                }

                ///////////////////////////////////////////////////////////////////////////////////////////
                //                            Si le joueur a perdu la partie                             //
                ///////////////////////////////////////////////////////////////////////////////////////////
                else
                {
                    Partie.afficherVague(Affichage.fenetre);

                    Affichage.afficheMessage(PARTIE);
                }

            }

            Partie.afficheZoneTower(Affichage.fenetre);
        }

        Affichage.fenetre.display();
        Affichage.fenetre.clear();

    }

    return 0;
}
