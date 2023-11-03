#include <cerrno>
#include <cfenv>
#include <cmath>
#include <iostream>

using namespace std;

// Read ints from cin and outputs the sqrt() of each int,
// or "no square root" if sqrt(x) is illegal for some x.
int main() {
    for (int x; cin >> x;) {
        errno = 0;
        feclearexcept(FE_ALL_EXCEPT);

        double r = sqrt(x);
        if (errno == EDOM || fetestexcept(FE_INVALID))
            cout << "no square root\n";
        else
            cout << r << '\n';
    }
    return 0;
}
