//
// Created by dylan on 12-11-2019.
// Function definitions for moving_rectangle.hpp
//

#include <SFML/Graphics.hpp>
#include <hwlib.hpp>
#include "moving_rectangle.hpp"

// Constructor for the moving_rectangle object
moving_rectangle::moving_rectangle(sf::Vector2f position, sf::Color color, sf::Vector2f size ) :
        rectangle(position, color, size)
{}

// Draws the rectangle onto the screen
void moving_rectangle::draw(sf::RenderWindow & window ) const {
    sf::RectangleShape rectangle;
    rectangle.setPosition(position);
    rectangle.setSize(size);
    rectangle.setFillColor(color);
    window.draw(rectangle);
}

// Moves the moving_rectangle in a direction by adding a vector to the position vector
// Example my_moving_rectangle.move(sf::Vector2f{ 6, 6 }) this will make the moving_rectangle move 6 pixels down and 6 pixels to the right
void moving_rectangle::move(sf::Vector2f delta ){
    position += delta;
}

// Moves the moving_rectangle to a new position
// Example my_moving_rectangle.move(sf::Vector2f{ 200.0, 240.0 }) this will move the moving_rectangle to the coordinates x = 200.0, y = 240.0
void moving_rectangle::jump(sf::Vector2f target ){
    position = target;
}

// Moves the moving_rectangle to a new position
// target.x and target.y get float casted so that they work with the floatRect position
// Example my_moving_rectangle.move(sf::Vector2f{ 200, 240 }) this will move the moving_rectangle to the coordinates x = 200.0, y = 240.0
void moving_rectangle::jump(sf::Vector2i target ){
    jump( sf::Vector2f(
            static_cast< float >( target.x ),
            static_cast< float >( target.y )
    ));
}

