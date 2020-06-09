//
// Created by dylan on 23-5-2020.
//

#ifndef CPSE2_GAME_DATA_HPP
#define CPSE2_GAME_DATA_HPP

#include <array>
#include <vector>

/// This class holds all the data that is used in game_logic
/// This way all the data is in a central place and when the game is running
/// values only need to added or removed

class data{
public:
    data(){};
    struct game_data_t{
        std::vector<bool> left_vector               = {};
        std::vector<bool> mid_vector                = {};
        std::vector<bool> right_vector              = {};
        std::vector<bool> top_horizon_vector        = {};
        std::vector<bool> mid_horizon_vector        = {};
        std::vector<bool> bot_horizon_vector        = {};
        std::vector<bool> diagonal_up               = {};
        std::vector<bool> diagonal_down             = {};
        std::vector<std::vector<bool>*> positions   = {};
        bool player;
        int x;
        int y;
    } gameData;

    void reset_to_default(){
        gameData.left_vector                        = {};
        gameData.mid_vector                         = {};
        gameData.right_vector                       = {};
        gameData.top_horizon_vector                 = {};
        gameData.mid_horizon_vector                 = {};
        gameData.bot_horizon_vector                 = {};
        gameData.diagonal_up                        = {};
        gameData.diagonal_down                      = {};
        gameData.player                             = false;
        gameData.x                                  = -1;
        gameData.y                                  = -1;
    }
};

#endif //CPSE2_GAME_DATA_HPP
