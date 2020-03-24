//
// Created by dylan on 3-3-2020.
// Hpp file containing the function declarations for the circle class
//

#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "drawable.hpp"

class circle : public drawable {
public:
    //Constructor for the circle object
    circle(sf::Vector2f position, float radius, sf::Color Color = sf::Color::White, sf::Vector2f size = sf::Vector2f(0.0, 0.0));

    //Draw function that creates and draws the circle on the window
    void draw( sf::RenderWindow & window ) const override;

    //Writes the object type back to the txt file
    void writeType(std::ofstream & output) override;

    //Writes the size and color of the circle to the txt file
    void writeSpecific(std::ofstream & output) override;

protected:
    float radius;
};

#endif