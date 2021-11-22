#include <iostream>

using namespace std;

int main() {
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        for(int i = 2; i <= N; i++) {
            int cnt = 0;
            while(N % i == 0) {
                cnt++;
                N /= i;
            }
            cout << i << ' ' << cnt << '\n';
        }
    }
}