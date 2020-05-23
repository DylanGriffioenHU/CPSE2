//
// Created by dylan on 22-4-2020.
//

#ifndef TIC_TAC_TOE_COMAND_LINE_INTERFACE_H
#define TIC_TAC_TOE_COMAND_LINE_INTERFACE_H


#include "game_interface.hpp"
#include <iostream>

/// This class allows a player to play the game via a command line interface
class comand_line_interface : public game_interface {
private:
    inline static bool pos_found = false;
public:
    void draw_moves(std::vector<game_moves> &moves) override;

    void end_game(float game_state) override;

    game_moves get_move(bool player) override;
};


#endif //TIC_TAC_TOE_COMAND_LINE_INTERFACE_H
