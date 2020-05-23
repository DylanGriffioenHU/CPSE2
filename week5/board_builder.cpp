//
// Created by dylan on 22-4-2020.
//

#include "board_builder.hpp"

/// Constructor of the class board_builder
/// \param window: Represents a reference to the window you wish to draw the board on
board_builder::board_builder(sf::RenderWindow &window): window(window){
    draw_board();
}


/// This function allows drawing of the columns that form the board
/// \param rect_position: Represents the position of a rectangle(columns)
/// \param rect_size: Represents the size of a rectangle(columns)
/// \param board_color: Represents the color of the board
void board_builder::draw_rectangle(sf::Vector2f &rect_position, sf::Vector2f &rect_size, sf::Color &board_color){
    sf::RectangleShape rectangleShape;
    rectangleShape.setPosition(rect_position);
    rectangleShape.setSize(rect_size);
    rectangleShape.setFillColor(board_color);
    window.draw(rectangleShape);

}


///This function will draw the play board by using the draw_rectangle function
void board_builder::draw_board() {
    draw_rectangle(colum1,colum2,color);
    draw_rectangle(colum3,colum2,color);
    draw_rectangle(colum4,colum5,color);
    draw_rectangle(colum6,colum5,color);
}