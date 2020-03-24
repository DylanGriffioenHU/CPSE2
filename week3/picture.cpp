//
// Created by dylan on 10-3-2020.
// Cpp file containing the function definitions for the picture classs
// Takes a given picture and turns it into an object that it can draw on the window
//

#include "picture.hpp"

//Constructor for the picture object
picture::picture(sf::Vector2f position, std::string filename):
    drawable(position),
    filename(filename)
    {
    texture.loadFromFile(filename);
    sprite.setTexture(texture);
    sprite.setPosition(position);
    sprite.setScale(sf::Vector2f(0.2, 0.2));
}

//Draw function used to draw the sprite of the picture on the window
void picture::draw( sf::RenderWindow & window)const {
    window.draw(sprite);
}

//Contains function used to check if the given point is inside the sprite
bool picture::contains(const sf::Vector2i & point){
    return  sprite.getGlobalBounds().contains(point.x, point.y);
}

//Function that instantly moves the sprite to the target location
//Do note that it puts the middle point of the sprite on the sprite on the target location
void picture::jump(sf::Vector2f target) {
    position = target;
    sprite.setPosition(target);
}

//Function that writes the picture type to a txt file
void picture::writeType(std::ofstream & output) { output << "PICTURE ";}

//Function that writes the name of the picture to the txt file
void picture::writeSpecific(std::ofstream & output)  {
    output << filename << '\n';
}

