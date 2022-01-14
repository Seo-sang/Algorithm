#include <iostream>

using namespace std;

const int MN = 2e9 + 1;

int main() {
    int N, M; cin >> N >> M;
    if(N == 1 || M == 1) {
        cout << 1;
        return 0;
    }
    if(M == 2) {
        if(N == 2) cout << 1;
        else cout << 2;
        return 0;
    }
    if(N == 2) {
        cout << min(4, (M + 1) / 2);
        return 0;
    }
    if(M < 7) {
        cout << min(4, M);
        return 0;
    }
    cout << M - 2;
}