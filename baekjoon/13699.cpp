#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MN = 36;
ll T[MN];

ll dfs(int n) {
    if(T[n] != -1) return T[n];

    T[n] = 0;

    for(int i = 1; i <= n; i++) {
        T[n] += dfs(n - i) * dfs(i - 1);
    }

    return T[n];
}

int main() {
    int N; cin >> N;
    memset(T, -1, sizeof(T));
    T[0] = 1;
    dfs(N);

    cout << T[N];
}