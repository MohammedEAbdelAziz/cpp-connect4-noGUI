#include "../include/Connect4.hpp"
#include <bits/stdc++.h>
using namespace std;

GameManager::GameManager(Board *bPtr, Player *playerPtr[2]) {
  boardPtr = bPtr;
  players[0] = playerPtr[0];
  players[1] = playerPtr[1];
}

void GameManager::run() {
  int x, y;

  boardPtr->display_board();

  while (!boardPtr->game_is_over()) {
    for (int i : {0, 1}) {
      players[i]->get_move(x, y);
      while (!boardPtr->update_board(x, y, players[i]->get_symbol())) {
        players[i]->get_move(x, y);
      }
      boardPtr->display_board();
      if (boardPtr->is_winner()) {
        cout << players[i]->to_string() << " wins\n";
        return;
      }
      if (boardPtr->is_draw()) {
        cout << "Draw!\n";
        return;
      }
    }
  }
}

// Give player a symbol to use in playing
// It can be X or O or others
// This is needed for computer players
// as it does not ask for a name
Player::Player(char symbol) { this->symbol = symbol; }

// Optionally, you can give him ID or order
// Like Player 1 and Player 2
Player::Player(int order, char symbol) {
  cout << "Welcome player " << order << endl;
  cout << "Please enter your name: ";
  cin >> name;
  this->symbol = symbol;
}

// Get desired move: x y (each between 0 and 2)
// Virtual (can change for other player types)
void Player::get_move(int &x, int &y) {
  cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
  cin >> x >> y;
}

// Give player info as a string
string Player::to_string() { return "Player: " + name; }

// Get symbol used by player
char Player::get_symbol() { return symbol; }

// Set player symbol and name as Random Computer Player
RandomPlayer::RandomPlayer(char symbol, int dimension) : Player(symbol) {
  this->dimension = dimension;
  this->name = "Random Computer Player";
  cout << "My names is " << name << endl;
}

// Generate a random move
void RandomPlayer::get_move(int &x, int &y) {
  x = (int)(rand() / (RAND_MAX + 1.0) * dimension);
  y = (int)(rand() / (RAND_MAX + 1.0) * dimension);
}
