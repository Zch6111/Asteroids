game:	main.cpp HighScores.cpp Menu.cpp Object.cpp Player.cpp Projectile.cpp Asteroid.cpp AsteroidCluster.cpp Upgrade.cpp SpeedUpgrade.cpp FireSpeedUpgrade.cpp
	g++ main.cpp HighScores.cpp Menu.cpp Object.cpp Player.cpp Projectile.cpp Asteroid.cpp AsteroidCluster.cpp Upgrade.cpp SpeedUpgrade.cpp FireSpeedUpgrade.cpp	-o	gameasteroids	-lsfml-graphics	-lsfml-window	-lsfml-system
gamerun:	main.cpp HighScores.cpp Menu.cpp Object.cpp Player.cpp Projectile.cpp Asteroid.cpp AsteroidCluster.cpp Upgrade.cpp SpeedUpgrade.cpp FireSpeedUpgrade.cpp
	g++     main.cpp HighScores.cpp Menu.cpp Object.cpp Player.cpp Projectile.cpp Asteroid.cpp AsteroidCluster.cpp Upgrade.cpp SpeedUpgrade.cpp FireSpeedUpgrade.cpp        -o	gameasteroids       -lsfml-graphics -lsfml-window   -lsfml-system
	./gameasteroids
debug:	*.cpp
	g++ CollisionTest.cpp Object.cpp Asteroid.cpp AsteroidCluster.cpp Player.cpp Projectile.cpp	-o	CollisionTest	-lsfml-graphics	-lsfml-window	-lsfml-system
	g++ UpgradeTest.cpp Object.cpp Player.cpp Projectile.cpp Upgrade.cpp SpeedUpgrade.cpp FireSpeedUpgrade.cpp	-o	UpgradeTest	-lsfml-graphics	-lsfml-window	-lsfml-system
clear:
	rm	-f	gameasteroids CollisionTest UpgradeTest	*.o
