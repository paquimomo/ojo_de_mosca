//
// Created by paxo on 25/05/2024.
//

#ifndef OJODEMOSCA_MOVE_H
#define OJODEMOSCA_MOVE_H

class Move {
private:
    sf::Vector2f& center;
    float moveSpeed;

public:
    Move(const sf::Vector2f& center, float speed) : center(const_cast<sf::Vector2f &>(center)), moveSpeed(speed) {}

    void handleInput() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            center.y -= moveSpeed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            center.y += moveSpeed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            center.x -= moveSpeed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            center.x += moveSpeed;
        }
    }

    sf::Vector2f getCenter() const {
        return center;
    }
};

#endif //OJODEMOSCA_MOVE_H
