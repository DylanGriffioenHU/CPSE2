//
// Created by dylan on 22-4-2020.
//

#ifndef TIC_TAC_TOE_BOARD_BUILDER_HPP
#define TIC_TAC_TOE_BOARD_BUILDER_HPP

#include <SFML/Graphics.hpp>
///This class will draw a board to play tic tac toe on
class board_builder {
private:
    sf::Vector2f colum1 = {0.0, 205.0};
    sf::Vector2f colum2 = {650.0, 20.0};
    sf::Vector2f colum3 = {0.0,430.0};
    sf::Vector2f colum4 = {205.0, 0.0};
    sf::Vector2f colum5 = {20.0,650.0};
    sf::Vector2f colum6 = {430.0,0.0};
    sf::Color color = sf::Color::Blue;
    sf::RenderWindow &window;
protected:
    void draw_rectangle(sf::Vector2f &rect_position, sf::Vector2f &rect_size, sf::Color &board_color);
    void draw_board();
public:
    board_builder(sf::RenderWindow &window);
};


#endif //TIC_TAC_TOE_BOARD_BUILDER_HPP
