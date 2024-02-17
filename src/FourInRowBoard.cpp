#include "../include/Connect4.hpp"
#include <iostream>
using namespace std;

FourInRowBoard::FourInRowBoard() {
    n_rows = 5;
    n_cols = 7;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++) {
            board[i][j] = ' ';
        }
    }
}

bool FourInRowBoard::update_board(int x, int y, char mark) {
  if (x < 0 || x >= n_rows || y < 0 || y >= n_cols) {
    return false;
  }
  if (board[x][y] != ' ') {
    return false;
  }
  for (int i = n_rows - 1; i >= 0; i--) {
    if (board[i][y] == ' ') {
      board[i][y] = mark;
      break;
    }
  }
  n_moves++;
  return true;
}

void FourInRowBoard::display_board() {
  cout << "  0   1   2   3   4   5   6" << endl;
  cout << "-----------------------------" << endl;
  for (int i = 0; i < n_rows; i++) {
    cout << "| ";
    for (int j = 0; j < n_cols; j++) {
      cout << board[i][j] << " | ";
    }
    cout << endl;
    cout << "-----------------------------" << endl;
  }
}

bool FourInRowBoard::is_winner() {
  for (int i = 0; i < n_rows; i++) {
    for (int j = 0; j < n_cols - 3; j++) {
      if (board[i][j] != ' ' && board[i][j] == board[i][j + 1] &&
          board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3]) {
        return true;
      }
    }
  }
  for (int i = 0; i < n_rows - 3; i++) {
    for (int j = 0; j < n_cols; j++) {
      if (board[i][j] != ' ' && board[i][j] == board[i + 1][j] &&
          board[i][j] == board[i + 2][j] && board[i][j] == board[i + 3][j]) {
        return true;
      }
    }
  }
  for (int i = 0; i < n_rows - 3; i++) {
    for (int j = 0; j < n_cols - 3; j++) {
      if (board[i][j] != ' ' && board[i][j] == board[i + 1][j + 1] &&
          board[i][j] == board[i + 2][j + 2] &&
          board[i][j] == board[i + 3][j + 3]) {
        return true;
      }
    }
  }
  for (int i = 0; i < n_rows - 3; i++) {
    for (int j = 3; j < n_cols; j++) {
      if (board[i][j] != ' ' && board[i][j] == board[i + 1][j - 1] &&
          board[i][j] == board[i + 2][j - 2] &&
          board[i][j] == board[i + 3][j - 3]) {
        return true;
      }
    }
  }
  return false;
}

bool FourInRowBoard::is_draw() { return n_moves == n_rows * n_cols; }

bool FourInRowBoard::game_is_over() { return is_winner() || is_draw(); }