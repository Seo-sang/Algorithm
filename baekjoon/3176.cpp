#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;

const int MN = 100001;
const int INF = 1e9;

vector<P> g[MN];
int h[MN], dp[20][MN];
int max_num[20][MN];
int min_num[20][MN];

int max_ans, min_ans;

void dfs(int n, int prev) {
    for(P nxt : g[n]) {
        if(nxt.first == prev) continue;
        h[nxt.first] = h[n] + 1;
        dp[0][nxt.first] = n;
        max_num[0][nxt.first] = nxt.second;
        min_num[0][nxt.first] = nxt.second;
        dfs(nxt.first, n);
    }
}

void LCA(int a, int b) {
    if(h[a] < h[b]) swap(a, b);

    int gap = h[a] - h[b];
    for(int i = 0; i < 20; i++) {
        if(gap & (1 << i)) {
            min_ans = min(min_ans, min_num[i][a]);
            max_ans = max(max_ans, max_num[i][a]);
            a = dp[i][a];
        }
    }
    if(a == b) return;

    for(int i = 19; i >= 0; i--) {
        if(dp[i][a] != dp[i][b]) {
            min_ans = min(min_ans, min_num[i][a]);
            max_ans = max(max_ans, max_num[i][a]);
            min_ans = min(min_ans, min_num[i][b]);
            max_ans = max(max_ans, max_num[i][b]);
            a = dp[i][a], b = dp[i][b];
        }
    }
    min_ans = min(min_ans, min(min_num[0][a], min_num[0][b]));
    max_ans = max(max_ans, max(max_num[0][a], max_num[0][b]));
    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for(int i = 0; i < N-1; i++) {
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
    }
    fill(&min_num[0][0], &min_num[19][N + 1], INF);
    fill(&max_num[0][0], &max_num[19][N + 1], 0);

    dfs(1, 0);

    for(int i = 1; i < 20; i++) {
        for(int j = 1; j <= N; j++) {
            int k = dp[i-1][j];
            dp[i][j] = dp[i-1][k];

            min_num[i][j] = min(min_num[i-1][j], min_num[i-1][k]);
            max_num[i][j] = max(max_num[i-1][j], max_num[i-1][k]);
        }
    }

    int K; cin >> K;
    while(K--) {
        int a, b; cin >> a >> b;
        min_ans = INF;
        max_ans = 0;
        LCA(a, b);
        cout << min_ans << ' ' << max_ans << '\n';
    }
}