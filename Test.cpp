// UpgradeTest.cpp
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cassert>
#include "Player.h"
#include "LivesUpgrade.h"
#include "FireSpeedUpgrade.h"
#include "SpeedUpgrade.h"

// Function to run the tests
void runUpgradeTests() {
    // Test 1: LivesUpgrade
    Player player;
    LivesUpgrade livesUpgrade;

    int initialLives = player.getLives();
    livesUpgrade.applyToPlayer(player);  // Apply LivesUpgrade
    assert(player.getLives() == initialLives + 1);  // Assert that lives increased by 1
    std::cout << "LivesUpgrade Test Passed!" << std::endl;

    // Test 2: FireSpeedUpgrade
    player.setFireRate(1.0f);  // Set an initial fire rate
    FireSpeedUpgrade fireSpeedUpgrade(0.2f);  // Create FireSpeedUpgrade that increases fire rate by 0.2

    float initialFireRate = player.getFireRate();
    fireSpeedUpgrade.applyToPlayer(player);  // Apply FireSpeedUpgrade
    assert(player.getFireRate() == initialFireRate - 0.2f);  // Assert that fire rate decreased
    std::cout << "FireSpeedUpgrade Test Passed!" << std::endl;

    // Test 3: SpeedUpgrade
    player.setMaxVelocity(5.0f);  // Set an initial max velocity
    SpeedUpgrade speedUpgrade(3.0f);  // Create SpeedUpgrade that increases speed by 3

    float initialMaxVelocity = player.getMaxVelocity();
    speedUpgrade.applyToPlayer(player);  // Apply SpeedUpgrade
    assert(player.getMaxVelocity() == initialMaxVelocity + 3.0f);  // Assert that max velocity increased
    std::cout << "SpeedUpgrade Test Passed!" << std::endl;
}

// Main function to run tests
int main() {
    runUpgradeTests();  // Run all upgrade tests
    return 0;  // Return success
}