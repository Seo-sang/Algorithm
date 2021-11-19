#include <iostream>

using namespace std;

int main() {
    long long N, P; cin >> N >> P;
    long long ans = 1;
    for(int i = 1; i <= N; i++) {
        ans *= (i % P);
        ans %= P;
    }
    cout << ans;
}