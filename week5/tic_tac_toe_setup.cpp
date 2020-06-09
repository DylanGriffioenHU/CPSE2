//
// Created by dylan on 23-5-2020.
//

#include "tic_tac_toe_setup.hpp"

/// Default constructor for the class tic_tac_toe_setup
tic_tac_toe_setup::tic_tac_toe_setup() {};


/// When starting a tic tac toe game the player has to select if he wants the game to be
/// in terminal mode or graphical user interface mode
void tic_tac_toe_setup::start_tic_tac_toe_setup() {
    std::cout << "Please select your preferred game mode" << std::endl;
    std::cout << "Press 1 for the graphical user interface version";
    std::cout << "Press 2 for the commandline version";
    std::cin >> player_choice;

    switch(player_choice){
        case 1:{
            sf::RenderWindow window{sf::VideoMode{650, 650},
                                    "Tic Tac Toe"};
            graphical_user_interface gui(window);
            game_logic game(gui);
            while(window.isOpen()){
                game.main();
                sf::sleep(sf::microseconds(20));
                sf::Event event;
                while(window.pollEvent(event)){
                    if(event.type == sf::Event::Closed){
                        window.close();
                    }
                }
            }
            break;
        }
        case 2:{
            command_line_interface cli;
            game_logic game(cli);
            game.main();
            break;
        }
        default:{
            std::cout << player_choice << " is not a valid game choice" << std::endl;
            std::cout << "Pls enter either 1 or 2" << std::endl;
            break;
        }
    }
}