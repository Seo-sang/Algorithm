#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long X, Y; cin >> X >> Y;
    long long Z = (Y * 100) / X;
    if(Z >= 99) {
        cout << -1;
        return 0;
    }

    long long l = 1, r = X;
    for(int i = 0; i < 40; i++) {
        long long mid = (l + r) / 2;
        long long tmp = (Y + mid) * 100 / (X + mid);
        if(Z != tmp) r = mid;
        else l = mid;
    }
    cout << r;
}