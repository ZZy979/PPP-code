#include <iostream>

using namespace std;

int main() {
    double temp = 1, total = 0;
    for (int i = 1; i <= 64; ++i) {
        total += temp;
        cout << "Square " << i << " needs " << temp << " grains of rice, "
                << total << " in total" << endl;
        temp *= 2;
    }
    return 0;
}
