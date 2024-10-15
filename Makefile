# Makefile

CXX = g++
CXXFLAGS = -std=c++11 -Wall -I/usr/local/include -L/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system

# Object files
OBJ = main.o Object.o Player.o Upgrade.o LivesUpgrade.o FireSpeedUpgrade.o SpeedUpgrade.o Projectile.o Enemy.o UpgradeTest.o

# Target executable
TARGET = game

# Rule for compiling the target
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Rule for compiling test executable
test: UpgradeTest.o Object.o Player.o LivesUpgrade.o FireSpeedUpgrade.o SpeedUpgrade.o
	$(CXX) UpgradeTest.o Object.o Player.o LivesUpgrade.o FireSpeedUpgrade.o SpeedUpgrade.o -o UpgradeTest

# Pattern rule for compiling .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJ) $(TARGET) UpgradeTest