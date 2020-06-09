//
// Created by dylan on 25-5-2020.
//

#include "board_builder.hpp"


/// Constructor of the class board_builder
/// \param window: A reference to the window you wish to draw the board on
board_builder::board_builder(sf::RenderWindow &window): window(window) {
    draw_board();
};

/// This function draws the colloms that form the tic tac toe board
/// \param rect_position: The position that the rectangle is drawn on
/// \param rect_size: the size of the rectangle
/// \param board_color: the color of the drawn rectangles
void board_builder::draw_rectangle(sf::Vector2f &rect_position, sf::Vector2f &rect_size, sf::Color &board_color) {
    sf::RectangleShape rectangleShape;
    rectangleShape.setPosition(rect_position);
    rectangleShape.setSize(rect_size);
    rectangleShape.setFillColor(board_color);
    window.draw(rectangleShape);
}

/// This function will draw the board by using the draw rectangle function
void board_builder::draw_board() {
    draw_rectangle(colum1, colum2, color);
    draw_rectangle(colum3, colum2, color);
    draw_rectangle(colum4, colum5, color);
    draw_rectangle(colum6, colum5, color);
}