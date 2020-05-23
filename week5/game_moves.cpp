//
// Created by dylan on 22-4-2020.
//

#include "game_moves.hpp"
/// Constructor of the class game_moves
/// \param player: Represents either player 1 or player 2
/// \param x_cor: Represents the x coordinate of the move
/// \param y_cor: Represents the y coordinate of the move
game_moves::game_moves(const bool &player, const int &x_cor, const int &y_cor):
        player(player), coordinates({x_cor,y_cor}){
};

/// This function gets the value of player and returns it
/// \return if true is returned this represents player 2 else this represents player 1
bool game_moves::get_player() const {
    return player;
}

/// This function gets the value of coordinates and returns it
/// \return: Represents the coordinates of the move
std::array<int, 2> game_moves::get_move() const {
    return coordinates;
}
