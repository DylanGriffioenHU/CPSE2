//
// Created by dylan on 25-5-2020.
//

#ifndef CPSE2_GAME_INTERFACE_HPP
#define CPSE2_GAME_INTERFACE_HPP

#include "game_moves.hpp"
#include <vector>

/// This class serves as an interface class for both the gui and cli version of tic tac toe
/// This way both version get to use these functions
class game_interface{
public:
    /// Default constructor for the class game_interface
    game_interface() = default;

    /// Virtual function that will return moves by using get_move from the game_moves class
    /// \param player: Represents either player 1 false or player 2 t rue
    /// \return: returns the coordinates of the move by the given player
    virtual game_moves get_move(const bool player){ return  game_moves(-1, -1, -1);}

    /// virtual function which will end the game when implemented
    /// \param game_state will return a game state(example won, loss or draw)
    virtual void end_game(const float game_state){};

    /// Virtual function that will draw moves on the screen
    /// \param moves: A vector of moves that you want to be displayed on the screen
    virtual void draw_moves(std::vector<game_moves> &moves){};
};

#endif //CPSE2_GAME_INTERFACE_HPP
