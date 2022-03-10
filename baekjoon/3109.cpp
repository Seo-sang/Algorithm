#include <bits/stdc++.h>

using namespace std;
string arr[10001];
bool vst[10001][501];
int dx[3] = {-1, 0, 1};
int dy[3] = {1, 1, 1};
int R, C;

bool dfs(int x, int y) {
    if(y == C - 1) {
        vst[x][y] = true;
        if(arr[x][y] == 'x') return false;
        return true;
    }
    for(int d = 0; d < 3; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(nx >= 0 && nx < R && ny >= 0 && ny < C) {
            if(vst[nx][ny] || arr[nx][ny] == 'x') continue;
            vst[nx][ny] = true;
            if(dfs(nx, ny))
                return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> R >> C;
    for(int i = 0; i < R; i++)
        cin >> arr[i];

    int ans = 0;
    for(int i = 0; i < R; i++) {
        if(arr[i][0] == 'x') continue;
        if(dfs(i, 0)) ans++;
    }

    cout << ans;
}