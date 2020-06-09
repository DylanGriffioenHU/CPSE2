//
// Created by dylan on 23-5-2020.
//

#ifndef CPSE2_TIC_TAC_TOE_SETUP_HPP
#define CPSE2_TIC_TAC_TOE_SETUP_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include "board_builder.hpp"
#include "graphical_user_interface.hpp"
#include "command_line_interface.hpp"
#include "game_logic.hpp"


/// This class allows the player to select the game type
class tic_tac_toe_setup {
private:
    int player_choice = -1;
public:
    tic_tac_toe_setup();
    void start_tic_tac_toe_setup();
};


#endif //CPSE2_TIC_TAC_TOE_SETUP_HPP
