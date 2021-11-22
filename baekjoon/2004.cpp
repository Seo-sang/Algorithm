#include <iostream>

using namespace std;

int main() {
    long long N, M; cin >> N >> M;

    int five = 0, two = 0;
    for(long long i = 5; i <= N; i *= 5) {
        five += (N / i);
    }
    for(long long i = 5; i <= M; i *= 5) {
        five -= (M / i);
    }
    for(long long i = 5; i <= N-M; i *= 5) {
        five -= ((N-M) / i);
    }

    for(long long i = 2; i <= N; i *= 2) {
        two += (N / i);
    }
    for(long long i = 2; i <= M; i *= 2) {
        two -= (M / i);
    }
    for(long long i = 2; i <= N-M; i *= 2) {
        two -= ((N-M) / i);
    }
    cout << min(two, five);
}