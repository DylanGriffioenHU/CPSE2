//
// Created by dylan on 12-11-2019.
// Contains the constructor definition for graphics_obects.hpp.
//

#include <SFML/Graphics.hpp>
#include "graphics_object.hpp"

graphics_object::graphics_object( sf::Vector2f position, sf::Color color) :
        position{ position }, color{color}
{}
