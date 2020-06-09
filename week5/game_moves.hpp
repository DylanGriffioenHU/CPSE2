//
// Created by dylan on 23-5-2020.
//

#ifndef CPSE2_GAME_MOVES_H
#define CPSE2_GAME_MOVES_H

#include <array>

/// This class stores the coordinates of a move made by a player and which player that was
class game_moves {
private:
    bool player;
    std::array<int, 2> coordinates;
public:
    game_moves(const bool &player, const int &x_cor, const int &y_cor);
    [[nodiscard]] bool get_player() const;
    [[nodiscard]] std::array<int,2> get_move() const;
};


#endif //CPSE2_GAME_MOVES_H
