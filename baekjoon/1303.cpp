#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;

const int MN = 101;

string board[MN];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
bool vst[MN][MN];


int main() {
    int N, M; cin >> N >> M;
    for(int i = 0; i < M; i++)
        cin >> board[i];
    int white = 0, blue = 0;
    
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(vst[i][j]) continue;
            int cnt = 1;
            vst[i][j] = true;
            queue<P> q;
            q.push(P(i, j));
            while(!q.empty()) {
                P now = q.front(); q.pop();
                for(int d = 0; d < 4; d++) {
                    int nx = now.first + dx[d];
                    int ny = now.second + dy[d];
                    if(nx >= 0 && nx < M && ny >= 0 && ny < N) {
                        if(vst[nx][ny] || board[i][j] != board[nx][ny]) continue;
                        vst[nx][ny] = true;
                        cnt++;
                        q.push(P(nx, ny));
                    }
                }
            }
            if(board[i][j] == 'W')
                white += cnt * cnt;
            else
                blue += cnt * cnt;
        }
    }
    
    cout << white << ' ' << blue;
}