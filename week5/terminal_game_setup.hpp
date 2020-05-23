//
// Created by dylan on 22-4-2020.
//

#ifndef TIC_TAC_TOE_TERMINAL_GAME_SETUP_HPP
#define TIC_TAC_TOE_TERMINAL_GAME_SETUP_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include "board_builder.hpp"
#include "graphical_user_interface.hpp"
#include "command_line_interface.hpp"
#include "game_logic.hpp"

/// This class allows the user to enter which game mode should be started
class terminal_game_setup {
private:
    int choice = -1;
public:
    terminal_game_setup();
    void start_game_setup();
};


#endif //TIC_TAC_TOE_TERMINAL_GAME_SETUP_HPP
