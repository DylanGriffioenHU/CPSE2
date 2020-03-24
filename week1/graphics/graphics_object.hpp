//
// Created by dylan on 12-11-2019.
// Superclass for all graphics objects.
// Every graphics object is required to have a sf::Vector2f position and a sf::Color color.
// And a draw and get_collider function which is required for object collision.
//

#ifndef CPSE2_GRAPHICS_OBJECT_HPP
#define CPSE2_GRAPHICS_OBJECT_HPP

#include <SFML/Graphics.hpp>

class graphics_object {
public:

    graphics_object( sf::Vector2f position, sf::Color color);

    virtual void draw( sf::RenderWindow & window ) const = 0;

    virtual sf::FloatRect get_collider() = 0;

protected:
    sf::Vector2f position;
    sf::Color color;
};

#endif //CPSE2_GRAPHICS_OBJECT_HPP
