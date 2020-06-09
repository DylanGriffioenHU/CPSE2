//
// Created by dylan on 23-5-2020.
//

#include "game_moves.hpp"

/// Constructor of the class game_moves
/// \param player: Represents either player 1 or player 2
/// \param x_cor: Represents: the x coordinate of the move
/// \param y_cor: Represents: the y coordinte of the move
game_moves::game_moves(const bool &player, const int &x_cor, const int &y_cor):
    player(player), coordinates({x_cor,y_cor}){};

/// This function gets the value of the player variable and returns it
/// \return: A boolean, true means player 2 and false means player 1
bool game_moves::get_player() const {
    return player;
}

/// This function gets the value of coordinates and returns it
/// \return: The coordinates of the move as an int array
std::array<int, 2> game_moves::get_move() const {
    return coordinates;
}