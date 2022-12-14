#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;

const int MN = 51;
int board[MN][MN];
int m[MN][MN];
int mapSize[MN * MN];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
set<P> s;

int main() {
    int N, M; cin >> M >> N;
    int roomCnt = 0, maxRoom = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> board[i][j];

    int mapCnt = 0, cnt;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(m[i][j] != 0) continue;
            roomCnt++;
            mapCnt++;
            cnt = 1;
            m[i][j] = mapCnt;
            queue<P> q;
            q.push({i, j});
            while(!q.empty()) {
                P now = q.front(); q.pop();
                for(int d = 0; d < 4; d++) {
                    int nx = now.first + dx[d];
                    int ny = now.second + dy[d];
                    if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                        if(m[nx][ny] == mapCnt) continue;
                        if(m[nx][ny] != 0) {
                            s.insert({mapCnt, m[nx][ny]});
                            continue;
                        }
                        if(board[now.first][now.second] & (1 << d)) continue;
                        m[nx][ny] = mapCnt;
                        cnt++;
                        q.push({nx, ny});
                    }
                }
            }
            mapSize[mapCnt] = cnt;
            maxRoom = max(maxRoom, cnt);
        }
    }


    int ans = 0;
    for(auto it = s.begin(); it != s.end(); it++) {
        ans = max(ans, mapSize[it->first] + mapSize[it->second]);
    }
    cout << roomCnt << '\n' << maxRoom << '\n' << ans;
}