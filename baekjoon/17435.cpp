#include <bits/stdc++.h>

using namespace std;
const int MN = 200001;
int dp[20][MN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int M; cin >> M;
    for(int i = 1; i <= M; i++)
        cin >> dp[0][i];

    for(int i = 1; i < 20; i++)
        for(int j = 1; j <= M; j++)
            dp[i][j] = dp[i-1][dp[i-1][j]];

    int Q; cin >> Q;
    while(Q--) {
        int n, x; cin >> n >> x;

        for(int i = 0; i < 20; i++)
            if(n & (1 << i))
                x = dp[i][x];

        cout << x << '\n';
    }
}