#include "../include/Connect4.hpp"
#include <iostream>
using namespace std;

static bool four_in_row_game() {
  bool first_time;
  int choice;
  Player *players[2];
  players[0] = new Player(1, 'x');

  cout << "Welcome to FCAI Four In a Row Game. :)\n";
  cout << "Press 1 if you want to play with computer: ";
  cin >> choice;
  if (choice != 1)
    players[1] = new Player(2, 'o');
  else
    players[1] = new RandomPlayer('o', 7);
  GameManager four_in_row_game(new FourInRowBoard(), players);
  four_in_row_game.runfour();
  int c;
  cout << "GGWP\n";
  cout << "Press (1) to go back to main menu or (0) to Exit: ";
  cin >> c;
  if (c == 1)
    return first_time = false;
  else
    exit(0);
}