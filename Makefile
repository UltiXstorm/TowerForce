all : TowerForce

TowerForce : Point.o Ennemi.o Tower.o Graphisme.o Bouton.o Message.o Jeu.o main.o
			g++ obj/Point.o obj/Ennemi.o obj/Tower.o obj/Graphisme.o obj/Bouton.o obj/Message.o obj/Jeu.o obj/main.o -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network -std=c++11 -o bin/TowerForce

main.o : src/sfml/Graphisme.h src/core/Jeu.h src/main.cpp
			g++ -g -Wall -c src/main.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network -std=c++11 -o obj/main.o

Jeu.o : src/core/Ennemi.h src/core/Tower.h src/core/Jeu.h src/core/Jeu.cpp
			g++ -g -Wall -c src/core/Jeu.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network -std=c++11 -o obj/Jeu.o

Graphisme.o : src/core/Jeu.h  src/sfml/Bouton.h src/sfml/Message.h src/sfml/Graphisme.h src/sfml/Graphisme.cpp
			g++ -g -Wall -c src/sfml/Graphisme.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network -std=c++11 -o obj/Graphisme.o

Bouton.o : src/core/Point.h src/sfml/Bouton.h src/sfml/Bouton.cpp
			g++ -g -Wall -c src/sfml/Bouton.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network -std=c++11 -o obj/Bouton.o

Message.o : src/core/Point.h src/sfml/Message.h src/sfml/Message.cpp
			g++ -g -Wall -c src/sfml/Message.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network -std=c++11 -o obj/Message.o

Tower.o : src/core/Point.h src/core/Tower.h src/core/Tower.cpp
			g++ -g -Wall -c src/core/Tower.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network -std=c++11 -o obj/Tower.o

Ennemi.o :  src/core/Point.h src/core/Ennemi.h src/core/Ennemi.cpp
			g++ -g -Wall -c src/core/Ennemi.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network -std=c++11 -o obj/Ennemi.o

Point.o : src/core/Point.h src/core/Point.cpp
			g++ -g -Wall -c src/core/Point.cpp -o obj/Point.o

tRegression.exe : Point.o Ennemi.o Tower.o tRegression.o
				g++ obj/Point.o obj/Ennemi.o obj/Tower.o obj/tRegression.o -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network -std=c++11 -o tRegression.exe

tRegression.o : src/core/Point.h src/core/Ennemi.h src/core/Tower.h src/testsRegression/testsClasse.cpp
				g++ -g -Wall -c src/testsRegression/testsClasse.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network -std=c++11 -o obj/tRegression.o

clean :
		rm obj/*

veryclean : clean
		rm bin/*

lancer: TowerForce
	./bin/TowerForce