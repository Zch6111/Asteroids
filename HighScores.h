#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// A struct to represent a player's high score entry (name and score)
struct ScoreEntry {
  std::string name;
  int score;
};

// The HighScores class manages saving and displaying high scores
class HighScores {
 private:
  std::vector<ScoreEntry> scores;  // Vector to hold high scores
  sf::Font font;                   // Font for rendering text
  std::string filename;            // File to store high scores
  int attemptCounter = 1;
  // Loads high scores from the file
  void loadFromFile();

 public:
  // Constructor: Takes the file path where high scores will be saved
  HighScores(const std::string& file);

  // Adds a new score and writes it to the file
  void addScore(int score);

  // Draws the high scores on the window
  void draw(sf::RenderWindow& window);

  // Clear the high score
  void clear();
};
