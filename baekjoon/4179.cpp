#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;

const int MN = 1001;
const int INF = 1e9;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
string board[MN];
queue<P> firearr;
int fire[MN][MN];
bool vst[MN][MN];
int R, C; 

struct edge {
    int x, y, cnt;
    edge(int x, int y, int cnt) : x(x), y(y), cnt(cnt) {}
};


int main() {
    fill(&fire[0][0], &fire[MN-1][MN], INF);
    cin >> R >> C;
    P pos;
    for(int i = 0; i < R; i++) {
        cin >> board[i];
        for(int j = 0; j < C; j++) {
            if(board[i][j] == 'J')
                pos = make_pair(i, j);
            else if(board[i][j] == 'F') {
                firearr.push(make_pair(i, j));
                fire[i][j] = 0;
            }
        }
    }
    if(pos.first == 0 || pos.first == R -1 || pos.second == 0 || pos.second == C - 1) {
        cout << 1;
        return 0;
    }

    while(!firearr.empty()) {
        P now = firearr.front(); firearr.pop();
        for(int d = 0; d < 4 ; d++) {
            int nx = now.first + dx[d];
            int ny = now.second + dy[d];
            if(nx >= 0 && nx < R && ny >= 0 && ny < C) {
                if(board[nx][ny] == '#') continue;
                if(fire[nx][ny] > fire[now.first][now.second] + 1) {
                    fire[nx][ny] = fire[now.first][now.second] + 1;
                    firearr.push(make_pair(nx, ny));
                }
            }
        }
    }


    queue<edge> q;
    memset(vst, 0, sizeof(vst));
    q.push(edge(pos.first, pos.second, 0));
    vst[pos.first][pos.second] = true;
    while(!q.empty()) {
        edge now = q.front(); q.pop();
        for(int d = 0; d < 4; d++) {
            int nx = now.x + dx[d];
            int ny = now.y + dy[d];
            if(nx >= 0 && nx < R && ny >= 0 && ny < C) {
                if(vst[nx][ny] || board[nx][ny] == '#') continue;
                vst[nx][ny] = true;
                if(fire[nx][ny] > now.cnt + 1) {
                    if(nx == 0 || nx == R-1 || ny == 0 || ny == C - 1) {
                        cout << now.cnt + 2;
                        return 0;
                    }
                    q.push(edge(nx, ny, now.cnt + 1));
                }
            }
        }
    }

    cout << "IMPOSSIBLE";
    
}