//
// Created by dylan on 12-11-2019.
// Subclass of graphics_object.
// This class is used to create rectangle objects.
//

#ifndef CPSE2_RECTANGLE_HPP
#define CPSE2_RECTANGLE_HPP


#include "graphics_object.hpp"

class rectangle : public graphics_object {
public:

    rectangle(sf::Vector2f position, sf::Color color, sf::Vector2f size);

    void draw(sf::RenderWindow & window ) const override;

    sf::FloatRect get_collider() override;

protected:
    sf::Vector2f size;
};



#endif //CPSE2_RECTANGLE_HPP
