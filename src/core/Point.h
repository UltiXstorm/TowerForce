/**
    @brief classe Point
	crée les points qui constituent le terrain
	@author p1507711
	@file Point.h
	@version 2.3
	@date 2018/02/27
*/

#ifndef Point_H_INCLUDED
#define Point_H_INCLUDED

#include "Constantes.h"


/**
    @brief Class Point

    Cette classe permet de gerer les points du terrain.
*/


class Point
{
    private:

        int x, y;

    public:

    	/**@brief Constructeur par défaut de Point
        @param none
        @return none
        @code
        Point();
        @endcode
        */
    	Point();

        /**@brief Constructeur avec paramètres de Point
        @param [nx] de type unsigned int
        @param [ny] de type unsigned int
        @return none
        @code
        Point(uint nx, uint ny);
        @endcode
        */
    	Point(uint nx, uint ny);

    	/**@brief Accesseur de l'abscisse
        @param none
        @return int
        @code
        int getX() const;
        @endcode */
    	int getX() const;

    	/**@brief Accesseur de l'ordonnée
        @param none
        @return int
        @code
        int getY() const;
        @endcode */
    	int getY() const;

    	/**@brief Mutateur de l'abscisse
        @param [nx] de type const int
        @return none
        @code
        void setX(const int nx);
        @endcode */
    	void setX(const int nx);

    	/**@brief Mutateur de l'ordonnée
        @param [ny] de type const int
        @return none
        @code
        void setY(const int ny);
        @endcode */
    	void setY(const int ny);

};

#endif


