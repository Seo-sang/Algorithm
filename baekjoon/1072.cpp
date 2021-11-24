#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long X, Y; cin >> X >> Y;
    long long Z = Y * 100 / X;
    if(Z >= 99) {
        cout << -1;
        return 0;
    }

    long long lo = 1, hi = X;
    for(int i = 0; i < 30; i++) {
        long long mid = (lo + hi) / 2;
        long long tmp = (mid + Y) * 100 / (mid + X);
        if(tmp != Z) hi = mid;
        else lo = mid;
    }
    cout << hi;
}