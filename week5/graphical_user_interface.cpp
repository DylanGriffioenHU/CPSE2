//
// Created by dylan on 26-5-2020.
//

#include "graphical_user_interface.hpp"

/// Constructor of the class graphica_user_interface
/// \param window: the windows you want the gui to be drawn on
graphical_user_interface::graphical_user_interface(sf::RenderWindow &window):
    window(window){}


/// this function takes the coordinates from moves and
/// uses those to draw images on the window
/// \param moves: a reference to a vector of valid game moves
void graphical_user_interface::draw_moves(std::vector<game_moves> &moves) {
    window.clear();
    board_builder boardBuilder(window);
    for(auto move : moves){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
            draw_image(!move.get_player(), (move.get_move()[0] * 255),(move.get_move()[1] * 255));
        }
        draw_image(move.get_player(), (move.get_move()[0] * 255),(move.get_move()[1] * 255));
    }
    window.display();
}

/// This function will draw the O and X images for the playermade moves
/// \param player: a boolean telling the function which player made the move
/// \param x_pos: a float value that contains the x coordinate of the move
/// \param y_pos: a float value that contains the y coordinate of the move
void graphical_user_interface::draw_image(bool player, float x_pos, float y_pos) {
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
    if(player){
        if(!(image.loadFromFile("X.png"))){
            std::cout << "Error reading image!" << std::endl;
        }
        texture.loadFromImage(image);
        sprite.setTexture(texture);
    } else {
        if(!(image.loadFromFile("O.png"))){
            std::cout << "Error reading image!" << std::endl;
        }
        texture.loadFromImage(image);
        sprite.setTexture(texture);
    }
    sprite.setPosition(x_pos, y_pos);
    window.draw(sprite);
}


/// If the game has ended this function will display either a
/// tie screen, a victyory player 1 screen or a victory player 2 screen
void graphical_user_interface::end_game(float game_state){
    window.clear();
    if(game_state == 0.5){
        draw_end_screen_image("Tie.png", 0, 0);
    } else if (game_state == 1){
        draw_end_screen_image("P2_win.png", 0, 0);
    } else {
        draw_end_screen_image("P1_win.png", 0, 0);
    }
    window.display();
}

game_moves graphical_user_interface::get_move(bool player) {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
        return game_moves(-2, -2, -2);
    } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        int x_pos, y_pos;
        auto mouse_pos = sf::Mouse::getPosition(window);

        if(mouse_pos.x >= 450.0){
            x_pos = 2;
        } else if(mouse_pos.x >= 255.0){
            x_pos = 1;
        } else{
            x_pos = 0;
        }

        if(mouse_pos.y >= 450.0){
            y_pos = 2;
        } else if(mouse_pos.y >= 255.0){
            y_pos = 1;
        } else {
            y_pos = 0;
        }
        return game_moves(player, x_pos, y_pos);
    }
    return game_moves(-1,-1,-1);
}

/// This function will draw game tie image
/// \param x_pos: The x position where the image wil be drawn
/// \param y_pos: The y position where the image will be drawn
void graphical_user_interface::draw_end_screen_image(std::string file_name, float x_pos, float y_pos) {
    window.clear();
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
    if(!image.loadFromFile(file_name)){
        std::cout << "error loading from file!" << std::endl;
    }
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.setPosition(x_pos,y_pos);
    window.draw(sprite);
}