//
// Created by dylan on 10-3-2020.
// Cpp file containing the function definitons for the drawable class
//

#include "drawable.hpp"

drawable::drawable(sf::Vector2f position, sf::Vector2f size, sf::Color Color ):
    position(position),
    size(size),
    Color(Color)
{}

//Jump function that instantly moves a drawable object to the given position
//Keep in mind that the function puts the middle point of the drawable object at the target location
void drawable::jump(sf::Vector2f target) {
    position = target;
}

//creates a temporary float rectangle around the drawable object
//It then checks if the given point is inside the rectangle
//And returns if that's true or not
bool drawable::contains(const sf::Vector2i & point){
    sf::FloatRect clickbox(position, size);
    return clickbox.contains(point.x, point.y);
}

//Function to write the drawable objects position to the txt file
void drawable::writeGeneral(std::ofstream & output){
    output << "(" << position.x << "," << position.y << ") ";
}

//Function that writes the color of an object to a txt file
//It gets the color from the object and then finds that color in the struct
//Then it gets the text version of that color and writes that to the txt file
void drawable::writeColor(std::ostream& output) {
    const struct { const char* name; sf::Color color; } colors[]{
            { "yellow", sf::Color::Yellow },
            { "red",    sf::Color::Red },
            { "green",    sf::Color::Green },
            { "blue",    sf::Color::Blue },
            { "black",    sf::Color::Black },
            { "white",    sf::Color::White },
    };
    for (auto const & colour : colors) {
        if (colour.color == Color) {
            output << colour.name << " ";
        }
    }
}

//Function that returns the drawable objects position;
sf::Vector2f drawable::getPosition(){return position;}
