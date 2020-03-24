//
// Created by dylan on 3-3-2020.
// Hpp file containing the function declarations for the picture class
// Takes a given picture and turns it into an object that it can draw on the window
//

#ifndef PICTURE_HPP
#define PICTURE_HPP

#include "drawable.hpp"

class picture : public drawable {
public:
    //Constructor for the picture object
    picture(sf::Vector2f position, std::string filename);

    //Draw function used to draw the sprite of the picture on the window
    void draw( sf::RenderWindow & window)const override;

    //Contains function used to check if the given point is inside the sprite
    bool contains(const sf::Vector2i & point) override;

    //Function that instantly moves the sprite to the target location
    //Do note that it puts the middle point of the sprite on the sprite on the target location
    void jump(sf::Vector2f target) override;

    //Function that writes the picture type to a txt file
    void writeType(std::ofstream & output) override;

    //Function that writes the name of the picture to the txt file
    void writeSpecific(std::ofstream & output) override;


private:
    std::string filename;
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif
