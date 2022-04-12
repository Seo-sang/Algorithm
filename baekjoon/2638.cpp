#include <bits/stdc++.h>

using namespace std;
const int MN = 101;
int N, M;
int board[MN][MN];
bool air[MN][MN], nxt[MN][MN];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
set<pair<int,int>> s;

void bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x, y});
    nxt[x][y] = true;
    while(!q.empty()) {
        pair<int,int> now = q.front(); q.pop();
        for(int d = 0; d < 4; d++) {
            int nx = now.first + dx[d];
            int ny = now.second + dy[d];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M && board[nx][ny] == 0 && nxt[nx][ny] == 0) {
                nxt[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int dfs(int n) {
    if(s.empty()) return n;
    set<pair<int,int>> nxts;
    memcpy(nxt, air, sizeof(nxt));
    for(auto it = s.begin(); it != s.end(); it++) {
        int cnt = 0;
        for(int d = 0; d < 4; d++) {
            int nx = it->first + dx[d];
            int ny = it->second + dy[d];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M && air[nx][ny]) cnt++;
        }
        if(cnt >= 2) bfs(it->first, it->second);
        else nxts.insert({it->first, it->second});
    }
    s = nxts;
    memcpy(air, nxt, sizeof(air));
    return dfs(n + 1);
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
            if(board[i][j] == 1) s.insert(make_pair(i, j));
        }
    }
    //공기 체크
    queue<pair<int,int>> q;
    q.push({0, 0});
    air[0][0] = true;
    while(!q.empty()) {
        pair<int,int> now = q.front(); q.pop();
        for(int d = 0; d < 4; d++) {
            int nx = now.first + dx[d];
            int ny = now.second + dy[d];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M && board[nx][ny] == 0 && air[nx][ny] == 0) {
                air[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    cout << dfs(0);
}