//
// Created by paxo on 25/05/2024.
//

#ifndef OJODEMOSCA_ANIMATION_H
#define OJODEMOSCA_ANIMATION_H

class Animation {
    sf::Clock clock;

public:
    Animation() {}

    float getDeltaTime() {
        return clock.restart().asSeconds();
    }

    void updateLines(std::vector<sf::VertexArray>& lines, const sf::Vector2f& center, float angleOffset) {
        for (auto& line : lines) {
            for (int i = 0; i < line.getVertexCount(); ++i) {
                sf::Vector2f currentPos = line[i].position;
                sf::Vector2f newPos;
                newPos.x = center.x + (currentPos.x - center.x) * cos(angleOffset) - (currentPos.y - center.y) * sin(angleOffset);
                newPos.y = center.y + (currentPos.x - center.x) * sin(angleOffset) + (currentPos.y - center.y) * cos(angleOffset);
                line[i].position = newPos;
            }
        }
    }
};

#endif //OJODEMOSCA_ANIMATION_H
