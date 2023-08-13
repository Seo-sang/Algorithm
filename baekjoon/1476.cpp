#include <bits/stdc++.h>

using namespace std;

int main() {
    int E, S, M; cin >> E >> S >> M;
    while(!(E == S && S == M)) {
        if(E <= S && E <= M) E += 15;
        else if(S <= E && S <= M) S += 28;
        else M += 19;
    }
    cout << E;
}