#ifndef _BALL_HPP
#define _BALL_HPP

//
// Created by dylan on 12-11-2019.
// Subclass of graphics_object.
// This class is used to create ball objects which can move and bounce off other graphics_objects.
//

#include <SFML/Graphics.hpp>
#include "graphics_object.hpp"

class ball : public graphics_object{
public:

	ball(sf::Vector2f position, sf::Vector2f direction = {1, 1} , sf::Color color = sf::Color ::White, float size = 30.0);
    sf::FloatRect get_collider() override;
	void draw( sf::RenderWindow & window ) const override;
    sf::Vector2f get_direction();
    void move( sf::Vector2f delta );
    void detect_collision(std::vector< graphics_object *> objects);

private:
	float size;
	sf::Vector2f direction;
};

#endif
