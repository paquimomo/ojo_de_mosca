//
// Created by paxo on 25/05/2024.
//

#ifndef OJODEMOSCA_OJODEMOSCA_H
#define OJODEMOSCA_OJODEMOSCA_H

class OjoDeMosca {
private:
    std::vector<sf::VertexArray> lines;
    std::vector<sf::Vector2f> vertices;
    sf::Vector2f center;

public:
    OjoDeMosca(int numVertices, const sf::Vector2f& center, float radius) : center(center) {
        float angleIncrement = 2 * M_PI / numVertices;
        for (int i = 0; i < numVertices; ++i) {
            float angle = i * angleIncrement;
            float x = center.x + radius * cos(angle);
            float y = center.y + radius * sin(angle);
            vertices.push_back(sf::Vector2f(x, y));
        }

        for (int i = 0; i < numVertices; ++i) {
            for (int j = 1; j < numVertices / 2; ++j) {
                int k = (i + j) % numVertices;
                sf::VertexArray line(sf::Lines, 2);
                line[0].position = vertices[i];
                line[0].color = sf::Color::Black;
                line[1].position = vertices[k];
                line[1].color = sf::Color::Black;
                lines.push_back(line);
            }
        }
    }

    const std::vector<sf::VertexArray>& getLines() const {
        return lines;
    }

    void setPosition(const sf::Vector2f& newPosition) {
        sf::Vector2f delta = newPosition - center;
        center = newPosition;
        for (auto& vertex : vertices) {
            vertex += delta;
        }
        for (auto& line : lines) {
            for (int i = 0; i < line.getVertexCount(); ++i) {
                line[i].position += delta;
            }
        }
    }

};

#endif //OJODEMOSCA_OJODEMOSCA_H
