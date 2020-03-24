//
// Created by dylan on 3-3-2020.
//

#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include <fstream>

class drawable {
public:
    //Constructor for drawable objects
    drawable(sf::Vector2f position, sf::Vector2f size = sf::Vector2f(30.0, 30.0), sf::Color Color = sf::Color::White );

    //Virtual draw function
    virtual void draw(sf::RenderWindow& window) const = 0;

    //Virtual jump function that instantly moves a drawable object to the given position
    //Keep in mind that the function puts the middle point of the drawable object at the target location
    //Requires the given position to be a float vector
    virtual void jump(sf::Vector2f target);

    //creates a temporary float rectangle around the drawable object
    //It then checks if the given point is inside the rectangle
    //And returns if that's true or not
    virtual bool contains(const sf::Vector2i & point);

    //Function to write the drawable objects position to a txt file
    void writeGeneral(std::ofstream & output);

    //Virtual function to write the type of the drawable object to a txt file
    virtual void writeType(std::ofstream & output){}

    //Virtual function to write object specific things to a txt file
    virtual void writeSpecific(std::ofstream & output){}

    //Function that writes the color of an object to a txt file
    //It gets the color from the object and then finds that color in the struct
    //Then it gets the text version of that color and writes that to the txt file
    void writeColor(std::ostream& output);

    //Function that returns the drawable objects position;
    sf::Vector2f getPosition();

protected:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Color Color;
};

#endif