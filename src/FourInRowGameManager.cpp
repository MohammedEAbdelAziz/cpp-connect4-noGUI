#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "../include/Connect4.hpp"
using namespace std;



void GameManager::runfour() {
    int y;
    int x = 0;
    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i:{0,1}) {
            players[i]->get_move(y);
            while (!boardPtr->update_board (x, y, players[i]->get_symbol())){
                players[i]->get_move(y);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner()){
                cout  << players[i]->to_string() << " wins\n";
                return;
            }
            if (boardPtr->is_draw()){
                cout << "Draw!\n";
                return;
            }
        }
    }
}