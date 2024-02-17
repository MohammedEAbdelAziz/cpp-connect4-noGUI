#include "./src/4_in_a_row_app.cpp"
#include <iostream>
using namespace std;

int main() {
  int x;
  bool Exit = false;
  bool first_time = true;

  while (!Exit) {
    if (first_time) {
      cout << "Welcome to Connect 4 \n";
      cout << "1- Play \n0- Exit \n";
      cin >> x;
      if (x == 1) {
        first_time = four_in_row_game();
      } else if (x == 0) {
        cout << "Goodbye \n";
        Exit = true;
      } else {
        cout << "Wrong input \n";
      }
    } else {
      cout << "Welcome Back! \n";
      cout << "I see you enjoyed that last one! \n";
      cout << "Get ready for a new round! \n\n";
      cout << "What do you want to do?: \n";
      cout << "1- Play another round \n0- Exit \n";
      cin >> x;
      if (x == 1) {
        first_time = four_in_row_game();
      } else if (x == 0) {
        cout << "Goodbye \n";
        Exit = true;
      } else {
        cout << "Wrong input \n";
      }
    }
  }
}