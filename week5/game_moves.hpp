//
// Created by dylan on 22-4-2020.
//

#ifndef TIC_TAC_TOE_GAME_MOVES_HPP
#define TIC_TAC_TOE_GAME_MOVES_HPP

#include <array>
#include <iostream>
#include "game_data.hpp"

/// This class saves and can return the player and coordinates of a done move
class game_moves {
private:
    bool player;
    std::array<int,2> coordinates;
public:
    game_moves(const bool &player, const int &x_cor, const int &y_cor);
    [[nodiscard]] bool get_player() const;
    [[nodiscard]] std::array<int,2> get_move() const;
};


#endif //TIC_TAC_TOE_GAME_MOVES_HPP
