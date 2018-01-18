#include <iostream>

using namespace std;

int main() {
    int x, n = 1;
    int primes[4] = {2, 3, 5, 7};
    for (auto p : primes) {
        cout << "Q " << p << "\n";
        cin >> x;
        while (x--) {
            n *= p;
        }
    }
    cout << "A " << n << "\n";
    return 0;
}