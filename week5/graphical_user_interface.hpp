//
// Created by dylan on 26-5-2020.
//

#ifndef CPSE2_GRAPHICAL_USER_INTERFACE_HPP
#define CPSE2_GRAPHICAL_USER_INTERFACE_HPP


#include <vector>
#include <SFML/Graphics.hpp>
#include "game_interface.hpp"
#include "board_builder.hpp"
#include "game_logic.hpp"

class graphical_user_interface : public game_interface {
private:
    sf::RenderWindow &window;
public:
    explicit  graphical_user_interface(sf::RenderWindow &window);
    void draw_image(bool player, float pos_x, float pos_y);

    void draw_end_screen_image(std::string file_name, float x_pos, float y_pos);

    void draw_moves(std::vector<game_moves> &moves) override;

    void end_game(float game_state) override;

    game_moves get_move(bool player) override;
};


#endif //CPSE2_GRAPHICAL_USER_INTERFACE_HPP
