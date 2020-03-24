//
// Created by dylan on 12-11-2019.
// Function definitions for rectangle.hpp
//

#include <SFML/Graphics.hpp>
#include "rectangle.hpp"

// Constructor for the rectangle object
rectangle::rectangle(sf::Vector2f position, sf::Color color, sf::Vector2f size) :
        graphics_object(position, color), size{size}
{}

// Draws the rectangle on the window
void rectangle::draw( sf::RenderWindow & window ) const {
    sf::RectangleShape rectangle;
    rectangle.setPosition(position);
    rectangle.setSize(size);
    rectangle.setFillColor(color);
    window.draw(rectangle);
}

// Creates and returns a FloatRect collider for the rectangle
sf::FloatRect rectangle::get_collider(){
    sf::FloatRect collider(position, size);
    return collider;
};

