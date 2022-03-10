#include <bits/stdc++.h>

using namespace std;

int main() {
    string S, T;
    cin >> S >> T;
    while(S.size() < T.size()) {
        if(T.back() == 'B') {
            T = T.substr(0, T.size() - 1);
            reverse(T.begin(), T.end());
        }
        else
            T = T.substr(0, T.size() - 1);
    }
    if(S == T) cout << 1;
    else cout << 0;
}