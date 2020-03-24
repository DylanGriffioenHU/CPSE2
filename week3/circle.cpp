//
// Created by dylan on 10-3-2020.
// Cpp file containing the function definitions for the circle class
//

#include "circle.hpp"

//Constructor for the circle object
circle::circle(sf::Vector2f position, float radius, sf::Color Color, sf::Vector2f size):
    drawable(position, sf::Vector2f(2*radius, 2*radius), Color),
    radius(radius)
{}

//Creates and draws a circle on the window
void circle::draw( sf::RenderWindow & window ) const{
    sf::CircleShape circle;
    circle.setRadius(radius);
    circle.setPosition(position);
    circle.setFillColor(Color);
    window.draw(circle);
}

//Writes the object type back to the txt file
void circle::writeType(std::ofstream & output) { output << "CIRCLE ";}

//Writes the size and color of the circle to the txt file
void circle::writeSpecific(std::ofstream & output) {
    writeColor(output);
    output << radius << '\n';
}
