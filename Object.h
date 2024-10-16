#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>
#include <cmath>

class Object : public sf::Drawable {
 protected:
  sf::Shape* shape;
  sf::Vector2f position;
  sf::Vector2f velocity;
  float rotation;
  float rotationSpeed;
  bool active;

 public:
  Object(sf::Shape* objectShape);
  Object(sf::Shape* objectShape, sf::Vector2f originPosition,
         sf::Vector2f originVelocity, float originRotation,
         float originRotationSpeed);
  virtual ~Object();

  void update(float deltaTime);
  bool checkCollision(const Object& other);
  virtual void onCollision(Object& other);

  // Getters
  sf::Vector2f getPosition() const;
  sf::Vector2f getVelocity() const;
  float getRotation() const;
  float getRotationSpeed() const;
  bool isActive() const;
  sf::Shape* getShape() const;

  // Setters
  void setPosition(sf::Vector2f newPosition);
  void setVelocity(sf::Vector2f newVelocity);
  void setRotation(float newRotation);
  void setRotationSpeed(float newRotationSpeed);
  void setActive(bool isActive);

 protected:
  virtual void draw(sf::RenderTarget& target,
                    sf::RenderStates states) const override;
};

#endif