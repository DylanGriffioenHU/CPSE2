//
// Created by dylan on 26-5-2020.
//

#include "command_line_interface.hpp"


/// Draws the moves and board on the terminal window
/// \param moves: a vector containing the playermade moves
void command_line_interface::draw_moves(std::vector<game_moves> &moves) {
    command_line_interface::pos_found = false;
    std::cout << std::endl;
    for(int y = 0; y < 3; y++){
        for(int x = 0; x < 3; x++){
            command_line_interface::pos_found = false;
            for(auto& move : moves){
                if(move.get_move()[0] == x && move.get_move()[1] == y){
                    command_line_interface::pos_found = true;
                    if(move.get_player()){
                        std::cout << " X ";
                    } else {
                        std::cout << " O ";
                    }
                }
            }
            if(!command_line_interface::pos_found){
                std::cout << "   ";
            }
            if(x < 2){
                std::cout << " | ";
            }
        }
        if(y < 2){
            std::cout << std::endl << "---------------" << std::endl;
        }
    }
    std::cout << std::endl;
}

/// This function  prints the endgame state either player 1 or 2 wins or tie
/// \param game_state: an int representing the game state, 1(win), 0(los) or 0.5(tie)
void command_line_interface::end_game(float game_state) {
    if(game_state == 0.5){
        std::cout << std::endl << "Game ended in a draw" << std::endl;
    } else {
        std::cout << std::endl << "Player number " << game_state + 1 << " has won the game" << std::endl;
    }
}

/// This function lets a player input a move and then saves it
/// \param player: a player number 0 for player 1 and 1 for player 2
/// \return the move a player made which is also saved in the game moves class
game_moves command_line_interface::get_move(const bool player) {
    int x,y;
    std::cout << std::endl << "Player number " << player + 1 << " Please give an x coordinate: ";
    std::cin >> x;
    std::cout << std::endl << "Player number " << player + 1 << " Please give an y coordinate: ";
    std::cin >> y;
    game_moves done_move(player, x,y);
    return done_move;
}