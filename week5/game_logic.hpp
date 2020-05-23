//
// Created by dylan on 22-4-2020.
//

#ifndef TIC_TAC_TOE_GAME_LOGIC_HPP
#define TIC_TAC_TOE_GAME_LOGIC_HPP

#include "game_moves.hpp"
#include "game_interface.hpp"
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "game_data.hpp"

/// This class houses all the logic of the game where all game moves and decisions are done
class game_logic {
private:
    data game_data;
    std::vector<game_moves> moves;
    game_interface &gameInterface;


public:
    explicit game_logic(game_interface &anInterface);
    bool move(game_moves move);
    float check_for_win();
    bool get_last_player();
    void main();

};


#endif //TIC_TAC_TOE_GAME_LOGIC_HPP
