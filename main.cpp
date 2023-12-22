#include <iostream>
#include <string>
#include "chess.h"

using namespace std;

int main() {
    Board b;
    string s;
    bool newGame = true;
    cin >> s;

    while(newGame) {
        b.setBoard();
        while (b.playGame()) {
            cout << "Do you want to play again? (y for yes, anything else for no) ";
            cin >> s;
            if (s != "y")
                newGame = false;
        }

    }

    return 0;
}