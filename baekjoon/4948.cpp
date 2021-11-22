#include <iostream>

using namespace std;

bool s[123456*2 + 1];

int main() {
    s[1] = 1;
    int N;
    for(int i = 2; i * i <= 123456*2 + 1; i++) {
        if(s[i]) continue;
        for(int j = i * 2; j <= 123456*2 + 1; j += i) {
            s[j] = 1;
        }
    }

    while(true) {   
        cin >> N;
        if(!N) break;
        int cnt = 0;
        for(int i = N + 1; i <= 2*N; i++) {
            if(!s[i]) cnt++;
        }
        cout << cnt << '\n';
    }
}