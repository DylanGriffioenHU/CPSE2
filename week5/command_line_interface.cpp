//
// Created by dylan on 22-4-2020.
//

#include "command_line_interface.hpp"

void comand_line_interface::draw_moves(std::vector<game_moves> &moves) {
    comand_line_interface::pos_found = false;
    std::cout << std::endl;
    for(int y= 0; y < 3; y++){
        for(int x = 0; x < 3; x++){
            comand_line_interface::pos_found = false;
            for(auto& move : moves){
                if(move.get_move()[0] == x && move.get_move()[1] == y){
                    comand_line_interface::pos_found = true;
                    if(move.get_player()){
                        std::cout << " X ";
                    } else{
                        std::cout << " O ";
                    }
                }
            }
            if(!comand_line_interface::pos_found){
                std::cout<< "   ";
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

void comand_line_interface::end_game(const float game_state) {
    if(game_state == 0.5){
        std::cout << std::endl << "Game ended in draw" << std::endl;
    } else{
        std::cout << std::endl << "Player number " << game_state + 1 << " has won the game " << std::endl;
    }

}

game_moves comand_line_interface::get_move(const bool player) {
    int x,y;
    std::cout << std::endl << "Player number " << player + 1 << " Please give an x coordinate: ";
    std::cin >> x;
    std::cout << std::endl << "Player number " << player + 1 << " Please give an y coordinate: ";
    std::cin >> y;
    game_moves done_move(player, x,y);
    return done_move;
}