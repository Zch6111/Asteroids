# Replace this with the path you get from `brew info sfml`
# g++ main.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system
SFML_PATH = /opt/homebrew/Cellar/sfml/2.6.1

# Replace "src" with the name of the folder where all your cpp code is
cppFileNames := $(shell find ./src -type f -name "*.cpp")

all: compile

compile:	
	mkdir -p bin
	g++ $(cppFileNames) -I$(SFML_PATH)/include -o bin/app -L$(SFML_PATH)/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
