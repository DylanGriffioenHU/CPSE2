//
// Created by dylan on 26-5-2020.
//

#ifndef CPSE2_COMMAND_LINE_INTERFACE_HPP
#define CPSE2_COMMAND_LINE_INTERFACE_HPP

#include "game_interface.hpp"
#include <iostream>

class command_line_interface : public game_interface{
private:
    inline static bool pos_found = false;
public:
    void draw_moves(std::vector<game_moves> &moves) override;

    void end_game(float game_state) override;

    game_moves get_move(bool player) override;
};


#endif //CPSE2_COMMAND_LINE_INTERFACE_HPP
