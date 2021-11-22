#include <iostream>

using namespace std;

bool s[1001];

int main() {
    int N; cin >> N;
    s[1] = 1;
    for(int i = 2; i * i <= 1000; i++) {
        if(s[i]) continue;
        for(int j = 2 * i; j <= 1000; j += i) {
            s[j] = 1;
        }
    }

    int a, ans = 0;
    while(N--) {
        cin >> a;
        if(!s[a]) ans++;
    }
    cout << ans;
}