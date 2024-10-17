game:	Asteroid.cpp	AsteroidCluster.cpp	HighScores.cpp	Menu.cpp	Object.cpp	Player.cpp	Projectile.cpp	main.cpp
	g++	Asteroid.cpp    AsteroidCluster.cpp      HighScores.cpp  Menu.cpp	Object.cpp	Player.cpp	Projectile.cpp	main.cpp	-o	sfml_menu	-lsfml-graphics	-lsfml-window	-lsfml-system
gamerun:	Asteroid.cpp    AsteroidCluster.cpp      HighScores.cpp  Menu.cpp	Object.cpp      Player.cpp      Projectile.cpp  main.cpp
	g++     Asteroid.cpp    AsteroidCluster.cpp      HighScores.cpp  Menu.cppObject.cpp      Player.cpp      Projectile.cpp  main.cpp        -o	sfml_menu       -lsfml-graphics -lsfml-window   -lsfml-system
	./game
clear:
	rm	-f	sfml_menu	*.o
