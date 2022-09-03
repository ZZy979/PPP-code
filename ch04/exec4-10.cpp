#include <cmath>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// rock-paper-scissors
int main() {
    const vector<string> moves = {"rock", "paper", "scissors"};
    int user_move, random;
    cout << "Welcome to Rock-paper-scissors!\n";
    cout << "Please enter your move (0 - rock, 1 - paper, 2 - scissors) and a random number\n";
    while (cin >> user_move >> random) {
        if (user_move < 0 || user_move > 2) {
            cout << "invalid move\n";
            continue;
        }
        int computer_move = int(100 * fabs(sin(random))) % 3;
        cout << "Your move is " << moves[user_move]
                << ", computer's move is " << moves[computer_move] << ". ";
        switch (user_move - computer_move) {
            case 0:
                cout << "Draw!\n";
                break;
            case -1: case 2:
                cout << "You lose!\n";
                break;
            case -2: case 1:
                cout << "You win!\n";
                break;
        }
    }
    cout << "Bye\n";
    return 0;
}
