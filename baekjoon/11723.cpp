#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int S = 0;
    int M; cin >> M;
    while(M--) {
        string str; cin >> str;
        int x;
        if(str == "add") {
            cin >> x;
            S |= (1 << x);
        }
        if(str == "remove") {
            cin >> x;
            S &= ~(1 << x);
        }
        if(str == "check") {
            cin >> x;
            cout << (S & (1 << x) ? 1 : 0) << '\n';
        }
        if(str == "toggle") {
            cin >> x;
            S ^= (1 << x);
        }
        if(str == "all") {
            S = (1 << 21) - 1;
        }
        if(str == "empty") {
            S = 0;
        }
    }
}