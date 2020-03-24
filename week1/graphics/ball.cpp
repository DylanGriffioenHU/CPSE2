//
// Created by dylan on 12-11-2019.
// Function definitions for ball.hpp
//


#include <SFML/Graphics.hpp>
#include <iostream>
#include "ball.hpp"

// Creates a ball object
// Example: ball my_ball{ sf::Vector2f{ 320.0, 240.0 }, sf::Vector2f{ 6, 6 }, sf::Color ::Blue, 30};
// Direction determines both the direction and the speed of the ball
ball::ball(sf::Vector2f position, sf::Vector2f direction, sf::Color color, float size) :
        graphics_object(position, color),
        size{ size }, direction{direction}
{}

// Draws a circle on the window
void ball::draw( sf::RenderWindow & window ) const {
	sf::CircleShape circle;
	circle.setRadius(size);
	circle.setFillColor(color);
	circle.setPosition(position);
	window.draw(circle);
}

// Moves the ball in a direction by adding a vector to the position vector
// Example my_ball.move(sf::Vector2f{ 6, 6 }) this will make the ball move 6 pixels down and 6 pixels to the right
void ball::move( sf::Vector2f delta ){
    position += delta;
}

// Creates and returns a sf::FloatRect collider for the ball object
// Since ball has a float size and not a float vector the function makes it a vector by using size * 2 for x and y
sf::FloatRect ball::get_collider(){
    sf::FloatRect collider(position, sf::Vector2f {size * 2, size * 2});
    return collider;
};

// Returns sf::Vector2f direction;
sf::Vector2f ball::get_direction(){
    return direction;
};

// Detects if the ball collides with another graphics_object
// The function loops through the objects array and for each object that isn't itself it will get that objects collider and check for collision by using intersects
// If there is collision it will then determine which side of the ball collided with the other object
// It does this by checking where the sf::FloatRect result is compared to its own collider and it then changes direction accordingly
void ball::detect_collision(std::vector< graphics_object *> objects){
    sf::FloatRect collider(position,sf::Vector2f{size * 2, size * 2});
    sf::Vector2f collider_middlepoint{collider.left + (collider.width / 2), (collider.top + (collider.height / 2))};
    for( auto & o : objects ){
        if(this != o){
            sf::FloatRect result;
            bool b3 = collider.intersects(o->get_collider(), result); // true
            if(b3 == true){
                if(result.left > collider_middlepoint.x){
                    if(direction.x > 0){direction.x = -direction.x;}
                }else if (result.left + result.width < collider_middlepoint.x){
                    if(direction.x < 0){direction.x = (direction.x * -1);}
                }else if (result.top + result.height < collider_middlepoint.y){
                    if(direction.y < 0){direction.y = (direction.y * -1);}
                }else if (result.top > collider_middlepoint.y){
                    if(direction.y > 0){direction.y = -direction.y;}
                }
            }
        }
    }
};

