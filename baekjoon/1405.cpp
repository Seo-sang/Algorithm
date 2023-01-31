#include <bits/stdc++.h>

using namespace std;
const int MN = 30;
int N;
int rate[4];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool vst[MN][MN];

double dfs(int n, int x, int y, double prob) {
    if(prob == 0) return 0;
    if(n == N) {
        return prob;
    }

    double ret = 0;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(vst[nx][ny]) continue;
        vst[nx][ny] = true;
        ret += dfs(n + 1, nx, ny, prob * rate[i] / 100);
        vst[nx][ny] = false;
    }
    
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    cout.precision(15);

    for(int i = 0; i < 4; i++) cin >> rate[i];
    vst[14][14] = true;
    cout << dfs(0, 14, 14, 1.0);
}