//
// Created by paxo on 25/05/2024.
//

#ifndef OJODEMOSCA_WINDOW_H
#define OJODEMOSCA_WINDOW_H

class Window {
    sf::RenderWindow window;

public:
    Window() {
        setWindow();
    }

    void setWindow() {
        window.create(sf::VideoMode(800, 600), "Ojo de Mosca");
    }

    void draw(const std::vector<Shape*>& shapes, const std::vector<OjoDeMosca*>& ojoDeMosca) {
        window.clear();
        for (const auto& shape : shapes) {
            window.draw(*shape->getDrawable());
        }
        for (const auto& ojo : ojoDeMosca) {
            for (const auto& line : ojo->getLines()) {
                window.draw(line);
            }
        }
        window.display();
    }

    sf::RenderWindow& getWindow() {
        return window;
    }
};

#endif //OJODEMOSCA_WINDOW_H
