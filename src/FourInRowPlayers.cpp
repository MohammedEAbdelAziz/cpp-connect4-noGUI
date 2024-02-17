#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "../include/Connect4.hpp"
using namespace std;




void Player::get_move (int& y) {
    cout << "\nPlease enter your move y (Column): ";
    cin >> y;
}

void RandomPlayer::get_move (int& y) {
    y = (int) (rand()/(RAND_MAX + 1.0) * dimension);
}