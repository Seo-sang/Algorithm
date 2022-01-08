#include <iostream>
#include <queue>

using namespace std;

const int MN = 101;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int N;
int board[MN][MN];
bool visit[MN][MN];
vector<pair<int,int>> g[10001];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;

    for(int i = 0;  i < N; i++) 
        for(int j = 0; j < N; j++)
            cin >> board[i][j];

    //대륙 분리
    int cnt = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(visit[i][j] || board[i][j] == 0) continue;
            g[cnt].push_back({i, j});
            queue<pair<int,int>> q;
            q.push({i, j});
            while(!q.empty()) {
                pair<int,int> now = q.front(); q.pop();
                for(int d = 0; d < 4; d++) {
                    int nx = now.first + dx[d];
                    int ny = now.second + dy[d];
                    if(nx >= 0 && nx < N && ny >= 0 && ny < N) {
                        if(visit[nx][ny] || board[nx][ny] == 0) continue;
                        visit[nx][ny] = true;
                        q.push({nx, ny});
                        g[cnt].push_back({nx, ny});
                    }
                }
            }
            cnt++;
        }
    }
    
    int ans = 1e9;
    for(int i = 0; i < cnt - 1; i++) 
        for(int j = i + 1; j < cnt; j++) 
            for(pair<int,int> e1 : g[i])
                for(pair<int,int> e2 : g[j])
                    ans = min(ans, abs(e1.first - e2.first) + abs(e1.second - e2.second));

    cout << ans - 1;
}