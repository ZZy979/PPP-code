#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

void generate_answer(vector<char>& answer);
void input_guess(vector<char>& guess);
int num_right_position(const vector<char>& answer, const vector<char>& guess);
int num_right_digit(const vector<char>& answer, const vector<char>& guess);
string to_string(vector<char>& answer);

// "Bulls and Cows" guessing game
int main() {
    const int n_digits = 4;
    const int n_chances = 8;
    vector<char> answer(n_digits), guess(n_digits);
    bool success = false;

    cout << "Welcome to Bulls and Cows game!" << endl;
    cout << "You have " << n_chances << " chances to guess "
            << n_digits << " different numbers." << endl;
    generate_answer(answer);
    for (int i = 1; i <= n_chances; ++i) {
        cout << "Input your guess: ";
        input_guess(guess);
        int bulls = num_right_position(answer, guess);
        int cows = num_right_digit(answer, guess) - bulls;
        if (bulls == 4) {
            success = true;
            break;
        }
        cout << i << '/' << n_chances << ": " << bulls << " bulls " << cows << " cows" << endl;
    }

    if (success)
        cout << "Congratulations, you guessed the right number!" << endl;
    else {
        cout << "Sorry, you haven't guessed the right number" << endl;
        cout << "Correct answer is: " << to_string(answer) << endl;
    }
    return 0;
}

// generate n different random numbers from 0~9
void generate_answer(vector<char>& answer) {
    string candidates = "0123456789";
    shuffle(candidates.begin(), candidates.end(), mt19937(random_device()()));
    copy(candidates.begin(), candidates.end(), answer.begin());
}

void input_guess(vector<char>& guess) {
    for (char& x: guess)
        cin >> x;
}

int num_right_position(const vector<char>& answer, const vector<char>& guess) {
    int n = 0;
    for (int i = 0; i < guess.size(); ++i)
        if (guess[i] == answer[i])
            ++n;
    return n;
}

int num_right_digit(const vector<char>& answer, const vector<char>& guess) {
    int n = 0;
    for (char x: guess)
        for (char y: answer)
            if (x == y)
                ++n;
    return n;
}

string to_string(vector<char>& answer) {
    ostringstream oss;
    for (char x : answer)
        oss << x;
    return oss.str();
}
