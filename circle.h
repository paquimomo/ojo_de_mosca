//
// Created by paxo on 25/05/2024.
//

#ifndef OJODEMOSCA_CIRCLE_H
#define OJODEMOSCA_CIRCLE_H

class Circle : public Shape {
    sf::CircleShape centralCircle;

public:
    Circle(const sf::Vector2f& center, float radius) {
        centralCircle.setRadius(radius);
        centralCircle.setFillColor(sf::Color::Red);
        centralCircle.setOrigin(radius, radius);
        centralCircle.setPosition(center);
        drawable = &centralCircle;
    }

    sf::Drawable* getDrawable() const override {
        return drawable;
    }

    sf::Vector2f getPosition() const override {
        return centralCircle.getPosition();
    }

    void setPosition(const sf::Vector2f& position) override {
        centralCircle.setPosition(position);
    }
};

#endif //OJODEMOSCA_CIRCLE_H
