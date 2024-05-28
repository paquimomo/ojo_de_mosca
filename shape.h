//
// Created by paxo on 25/05/2024.
//

#ifndef OJODEMOSCA_SHAPE_H
#define OJODEMOSCA_SHAPE_H

class Shape {
protected:
    sf::Drawable* drawable;

public:
    virtual sf::Drawable* getDrawable() const = 0;
    virtual void setPosition(const sf::Vector2f& position) = 0;
    virtual sf::Vector2f getPosition() const = 0;
};

#endif //OJODEMOSCA_SHAPE_H
