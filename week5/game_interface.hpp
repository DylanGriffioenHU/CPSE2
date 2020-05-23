//
// Created by dylan on 22-4-2020.
//


#ifndef TIC_TAC_TOE_GAME_INTERFACE_HPP
#define TIC_TAC_TOE_GAME_INTERFACE_HPP

#include "game_moves.hpp"
#include <vector>

/// This class makes it possible to implement the functions in this class in every
/// game interface that a player can use for playing the game like a gui or cli
class game_interface {
public:
    /// default constructor of the class game_interface
    game_interface() = default;

    /// virtual function that will return moves by using get_move from game_moves class when implemented
    /// \param player: Represents either player 1 false or player 2 true
    /// \return returns the coordinates of the played move by the given player
    virtual game_moves get_move(const bool player){ return game_moves(-1,-1,-1); }

    /// virtual function which will end the game when implemented
    /// \param game_state will return a game state like won loss or draw
    virtual void end_game(const float game_state){};

    /// virtual function that will draw moves on the screen when implemented
    /// \param moves: Represents a vector of moves a player had done
    virtual void draw_moves(std::vector<game_moves> &moves){};

};


#endif //TIC_TAC_TOE_GAME_INTERFACE_HPP
