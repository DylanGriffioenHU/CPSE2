//
// Created by dylan on 22-4-2020.
//

#ifndef TIC_TAC_TOE_GAME_DATA_HPP
#define TIC_TAC_TOE_GAME_DATA_HPP

#include <array>
#include <vector>

/// This class holds all the data that is used in game_logic so all the data
/// is on a central place and during iterations only values need to either be added or removed
/// the initialization of vectors and other values will remain
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
        gameData.left_vector            = {};
        gameData.mid_vector             = {};
        gameData.right_vector           = {};
        gameData.top_horizon_vector     = {};
        gameData.mid_horizon_vector     = {};
        gameData.bot_horizon_vector     = {};
        gameData.diagonal_up            = {};
        gameData.diagonal_down          = {};
        gameData.positions              = {};
        gameData.player                 = false;
        gameData.x                      = -1;
        gameData.y                      = -1;
    }

};


#endif //TIC_TAC_TOE_GAME_DATA_HPP
