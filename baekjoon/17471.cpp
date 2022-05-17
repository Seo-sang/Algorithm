#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;
const int MN = 11;
const int INF = 1e9;
int population[MN];
vector<int> g[MN];
int dp[(1 << MN)];
int N;
int ans = INF;


void bfs(int n) {
    queue<int> q;
    int vst = 0;
    int sum = 0;
    for(int i = 0; i < N; i++) {
        if(n & (1 << i)) {
            q.push(i);
            vst = (1 << i);
            sum = population[i];
            break;
        }
    }
    if(vst == n) {
        dp[n] = sum;
        return;
    }
    while(!q.empty()) {
        int now = q.front(); q.pop();
        for(int nxt : g[now]) {
            if(vst & (1 << nxt) || !(n & (1 << nxt))) continue;
            vst |= (1 << nxt);
            sum += population[nxt];
            if(vst == n) {
                dp[vst] = sum;
                return;
            }
            q.push(nxt);
        }
    }
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> population[i];
    for(int i = 0; i < N; i++) {
        int num; cin >> num;
        while(num--) {
            int a; cin >> a;
            g[i].push_back(a - 1);
        }
    }
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < (1 << N); i++)
        bfs(i);
    for(int i = 0; i < (1 << N); i++) {
        if(dp[i] != -1 && dp[((1 << N) - 1) - i] != -1) {
            ans = min(ans, abs(dp[i] - dp[((1 << N) - 1) - i]));
        }
    }
            
    if(ans == INF) cout << -1;
    else cout << ans;
}