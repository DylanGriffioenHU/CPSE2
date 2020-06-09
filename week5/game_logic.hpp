//
// Created by dylan on 23-5-2020.
//

#ifndef CPSE2_GAME_LOGIC_HPP
#define CPSE2_GAME_LOGIC_HPP

#include "game_moves.hpp"
#include "game_interface.hpp"
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "game_data.hpp"

/// This class contains all the logic needed to make the game work
/// It handles all the players moves and game decisions

class game_logic {
private:
    data game_data;
    std::vector<game_moves> moves;
    game_interface &gameInterface;
public:
    explicit game_logic(game_interface &an_interface);
    bool move(game_moves move);
    float check_for_win();
    bool get_last_player();
    void main();

};

#endif //CPSE2_GAME_LOGIC_HPP
