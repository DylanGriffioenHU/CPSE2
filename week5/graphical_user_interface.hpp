//
// Created by dylan on 22-4-2020.
//

#ifndef TIC_TAC_TOE_GRAPHICAL_USER_INTERFACE_HPP
#define TIC_TAC_TOE_GRAPHICAL_USER_INTERFACE_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "game_interface.hpp"
#include "board_builder.hpp"
#include "game_logic.hpp"

/// This class serves the user a gui for playing the game
class graphical_user_interface : public game_interface {
private:
    sf::RenderWindow &window;
    float x_pos = -1;
    float y_pos = -1;
public:
    explicit graphical_user_interface(sf::RenderWindow &a_window);
    void draw_image(bool player, float pos_x, float pos_y);

    void draw_tie_image(float pos_x, float pos_y);

    void draw_moves(std::vector<game_moves> &moves) override ;

    void end_game(float game_state) override;

    game_moves get_move(bool player) override;
};


#endif //TIC_TAC_TOE_GRAPHICAL_USER_INTERFACE_HPP
