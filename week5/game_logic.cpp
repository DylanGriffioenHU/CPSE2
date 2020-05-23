//
// Created by dylan on 22-4-2020.
//

//
// Created by ramon on 29-3-2020.
//

#include "game_logic.hpp"

/// The constructor of the game logic class
/// \param anInterface: Represents a reference to the chosen interface either cli or gui
game_logic::game_logic(game_interface &anInterface): gameInterface(anInterface){};

/// This function sets the move done by a player and checks if it is a valid move
/// \param move: an object of the class game_move so its functions can be used
/// \return: returns a boolean to indicate if a move is valid and has been done (pushed to moves vector)
bool game_logic::move(game_moves move) {
    if(move.get_move()[0] == -2 || move.get_move()[1] == -2){
        if(!moves.empty()){
            moves.pop_back();
            sf::sleep(sf::milliseconds(500));
            return true;
        }
        return false;
    }
    for(auto m : moves){
        if(move.get_move() == m.get_move()){
            return false;
        }
    }
    if(!(move.get_move()[0] == -1 || move.get_move()[1] == -1)){
        moves.push_back(move);
        return true;
    }
    return false;
}


/// This function sets where moves have been done and checks
/// all positions to see what the end game state has been reached
/// \return either a win/loss for a player(1) a continue game(0) or tie(0.5)
float game_logic::check_for_win() {

    for(auto move : moves){
        game_data.gameData.player = move.get_player();
        game_data.gameData.x = move.get_move()[0];
        game_data.gameData.y = move.get_move()[1];

        if(game_data.gameData.x == 0){game_data.gameData.left_vector.push_back(game_data.gameData.player);}
        if(game_data.gameData.x == 1){game_data.gameData.mid_vector.push_back(game_data.gameData.player);}
        if(game_data.gameData.x == 2){game_data.gameData.right_vector.push_back(game_data.gameData.player);}

        if(game_data.gameData.y == 0){game_data.gameData.top_horizon_vector.push_back(game_data.gameData.player);}
        if(game_data.gameData.y == 1){game_data.gameData.mid_horizon_vector.push_back(game_data.gameData.player);}
        if(game_data.gameData.y == 2){game_data.gameData.bot_horizon_vector.push_back(game_data.gameData.player);}

        if( game_data.gameData.x == game_data.gameData.y){game_data.gameData.diagonal_down.push_back(game_data.gameData.player);}
        if(( game_data.gameData.x == 0 && game_data.gameData.y == 2)
           || ( game_data.gameData.x == 1 && game_data.gameData.y == 1)
           || ( game_data.gameData.x == 2 && game_data.gameData.y == 0)){
            game_data.gameData.diagonal_up.push_back(game_data.gameData.player);
        }
    }
    game_data.gameData.positions = {&game_data.gameData.left_vector, &game_data.gameData.mid_vector,
                                    &game_data.gameData.right_vector, &game_data.gameData.top_horizon_vector,
                                    &game_data.gameData.mid_horizon_vector, &game_data.gameData.bot_horizon_vector,
                                    &game_data.gameData.diagonal_up, &game_data.gameData.diagonal_down};
    for(auto pos : game_data.gameData.positions){
        if (pos->size() == 3 && pos->at(0) == pos->at(1) && pos->at(0) == pos->at(2)) {
            return 1;
        }
    }
    if(moves.size() > 8){
        return 0.5;
    }
    game_data.reset_to_default();
    return 0;
}

/// Returns the last player that has done a move by getting the back of the moves vector
/// \return: a boolean 1 or 0 representing either player 2 or player 1
bool game_logic::get_last_player() {
    return moves.back().get_player();
}

/// class main function to be called so it can start a game loop
void game_logic::main() {
    bool player = false;
    while(check_for_win() == 0.0){
        if(move(gameInterface.get_move(player))){
            player = !(player);
        }
        gameInterface.draw_moves(moves);
        sf::sleep(sf::milliseconds(10));
    }
    if(check_for_win() == 0.5){
        gameInterface.end_game(0.5);
    } else{
        gameInterface.end_game(get_last_player());
    }
};

