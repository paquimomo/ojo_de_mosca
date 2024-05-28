// programa.h
//
// Created by paxo on 25/05/2024.
//

#ifndef OJODEMOSCA_PROGRAMA_H
#define OJODEMOSCA_PROGRAMA_H

class Programa {
public:
    static void iniciar() {

        //comenzamos el game loop
        while (true) {

            //declaramos el numero de vertices y circulos que el usuario desee
            int numVertices = getNumVertices();
            int numCircles = getNumCircles();

            //declaramos la posicion central del circulo y su radio
            sf::Vector2f initialCenter(200.0f, 300.0f);
            float radius = 100.0f;

            //declaramos la velocidad a la cual se moveran los circulos con las flechitas
            float moveSpeed = 0.1f;

            //creamos los vectores shapes que en este caso son los circulos y sus respectivos ojos de mosca
            std::vector<Shape*> shapes = createShapes(numCircles, initialCenter, radius);
            std::vector<OjoDeMosca*> ojos = createOjos(numVertices, numCircles, initialCenter, radius);

            //iniciamos la ventana con la funcionalidad del programa
            runProgram(initialCenter, moveSpeed, shapes, ojos, numVertices, radius);

            // Liberar la memoria
            for (auto shape : shapes) {
                delete shape;
            }

            for (auto ojo : ojos) {
                delete ojo;
            }
        }
    }

private:
    //le preguntamos al usuario por el numero de vertices que tendra el ojo de mosca
    static int getNumVertices() {
        int numVertices;
        std::cout << "Introduce el numero de vertices (entre 5 y 30): ";
        std::cin >> numVertices;
        while (numVertices < 5 || numVertices > 30) {
            std::cout << "Numero invalido. Introduce un numero entre 5 y 30: ";
            std::cin >> numVertices;
        }
        return numVertices;
    }

    //le preguntamos al usuario cuantos circulos va a querer en la pantalla
    static int getNumCircles() {
        int numCircles;
        std::cout << "Introduce el numero de circulos: ";
        std::cin >> numCircles;
        return numCircles;
    }

    //creamos el vector de shapes por cada figura dada por el usuario
    static std::vector<Shape*> createShapes(int numCircles, const sf::Vector2f& initialCenter, float radius) {
        std::vector<Shape*> shapes;
        for (int i = 0; i < numCircles; ++i) {
            sf::Vector2f center = initialCenter + sf::Vector2f(i * 220.0f, 0);
            shapes.push_back(new Circle(center, radius));
        }
        return shapes;
    }

    //creamos el vector ojo de mosca para "implementarlo" en cada circulo dibujado
    static std::vector<OjoDeMosca*> createOjos(int numVertices, int numCircles, const sf::Vector2f& initialCenter, float radius) {
        std::vector<OjoDeMosca*> ojos;
        for (int i = 0; i < numCircles; ++i) {
            sf::Vector2f center = initialCenter + sf::Vector2f(i * 220.0f, 0);
            ojos.push_back(new OjoDeMosca(numVertices, center, radius));
        }
        return ojos;
    }

    //funcion para añadir nuevos circulos mientras el programa este en curso
    static void newCircle(std::vector<Shape*>& shapes, std::vector<OjoDeMosca*>& ojos, int numVertices, float radius, bool& enterPressed, bool& deletePressed) {
        sf::Vector2f initialCenter(200.0f, 300.0f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            if (!enterPressed) {
                sf::Vector2f center = initialCenter + sf::Vector2f(shapes.size() * 220.0f, 0);
                shapes.push_back(new Circle(center, radius));
                ojos.push_back(new OjoDeMosca(numVertices, center, radius));
                enterPressed = true;
            }
        }
        else {
            enterPressed = false;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete)) {
            if (!deletePressed && !shapes.empty() && !ojos.empty()) {
                delete shapes.back();
                shapes.pop_back();
                delete ojos.back();
                ojos.pop_back();
                deletePressed = true;
            }
        }
        else {
            deletePressed = false;
        }

    }

    //logica del programa en la ventana
    static void runProgram(const sf::Vector2f& initialCenter, float moveSpeed, std::vector<Shape*>& shapes, std::vector<OjoDeMosca*>& ojos, int numVertices, float radius) {
        Window window;
        Animation animation;
        Move move(initialCenter, moveSpeed);
        bool enterPressed = false;
        bool deletePressed = false;

        while (window.getWindow().isOpen()) {
            sf::Event event;
            while (window.getWindow().pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.getWindow().close();
            }

            newCircle(shapes, ojos, numVertices, radius, enterPressed, deletePressed);
            move.handleInput();
            sf::Vector2f newCenter = move.getCenter();
            float deltaTime = animation.getDeltaTime();
            float angleOffset = 2 * M_PI * deltaTime / 10.0f;

            for (size_t i = 0; i < shapes.size(); ++i) {
                sf::Vector2f offset(i * 220.0f, 0);
                shapes[i]->setPosition(newCenter + offset);
                ojos[i]->setPosition(newCenter + offset);
                animation.updateLines(const_cast<std::vector<sf::VertexArray>&>(ojos[i]->getLines()), newCenter + offset, angleOffset);
            }

            window.draw(shapes, ojos);
        }
    }
};

#endif //OJODEMOSCA_PROGRAMA_H
