#include <iostream>

using namespace std;

bool s[1000001];

int main() {
    int M, N; cin >> M >> N;
    s[1] = 1;

    for(int i = 2; i * i <= N; i++) {
        if(s[i]) continue;
        for(int j = i * 2; j <= N; j += i) {
            s[j] = 1;
        }
    }

    for(int i = M; i <= N; i++) {
        if(!s[i]) cout << i <<'\n';
    }
}