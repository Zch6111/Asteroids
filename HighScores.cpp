#include "HighScores.h"

// Constructor: Initializes the high scores by loading from a file
HighScores::HighScores(const std::string& file) : filename(file) {
  // Load font for displaying high scores
  if (!font.loadFromFile("OpenSans-Bold.ttf")) {
    std::cerr << "Error loading font" << std::endl;
  }

  // Load high scores from file
  loadFromFile();
}

// Loads the high scores from the specified file
void HighScores::loadFromFile() {
  std::ifstream inputFile(filename);
  if (inputFile.is_open()) {
    scores.clear();
    std::string name;
    int score;

    // Read name and score from file and populate the scores vector
    while (inputFile >> name >> score) {
      scores.push_back(ScoreEntry{name, score});
    }
    inputFile.close();
  } else {
    std::cerr << "Unable to open high scores file!" << std::endl;
  }
}

// Adds a new high score entry and saves it to the file
void HighScores::addScore(int score) {
  // print attempts
  std::string name = "Attempt" + std::to_string(attemptCounter);
  // Add the attempts
  attemptCounter++;
  // Add the new score to the scores list
  scores.push_back(ScoreEntry{name, score});

  // Sort the scores in descending order based on the score value
  std::sort(scores.begin(), scores.end(),
            [](const ScoreEntry& a, const ScoreEntry& b) {
              return a.score > b.score;
            });

  // Write the updated scores to the file
  std::ofstream outputFile(filename);
  if (outputFile.is_open()) {
    for (const auto& entry : scores) {
      outputFile << entry.name << " " << entry.score << std::endl;
    }
    outputFile.close();
  } else {
    std::cerr << "Unable to write to high scores file!" << std::endl;
  }
}

// Draws the high scores on the window
void HighScores::draw(sf::RenderWindow& window) {
  // Create a title text for "High Scores"
  sf::Text title;
  title.setFont(font);
  title.setString("High Scores");
  title.setCharacterSize(50);
  title.setFillColor(sf::Color::Yellow);
  title.setPosition(250, 50);  // Position the title in the center of the window
  window.draw(title);

  // Display each high score entry below the title
  for (size_t i = 0; i < scores.size() && i < 10;
       i++) {  // Limit to top 10 scores
    sf::Text entryText;
    entryText.setFont(font);
    entryText.setCharacterSize(30);
    entryText.setFillColor(sf::Color::White);

    // Create the text "name: score" format
    entryText.setString(scores[i].name + ": " +
                        std::to_string(scores[i].score));

    // Set the position of each score entry
    entryText.setPosition(250,
                          150 + i * 40);  // Vertically space out the entries

    // Draw the entry text on the window
    window.draw(entryText);
  }
}
void HighScores::clear() { scores.clear(); }