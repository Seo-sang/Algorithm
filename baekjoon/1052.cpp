#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K; cin >> N >> K;
    int i;

    while(K > 1) {
        if(N <= K) {
            cout << 0;
            return 0;
        }
        int i = 1;
        while(true) {
            if((i << 1) > N) break;
            i <<= 1;
        }
        N -= i;
        K--;
    }
    i = 1;
    while(true) {
        if(i >= N) break;
        i <<= 1;
    }

    cout << i - N;
}