#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>

using namespace std;

const int MN = 51;
const int INF = 1e9;

int R, C;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

string board[MN];
int water[MN][MN];

struct edge {
    int x, y, score;
};

int main() {
    cin >> R >> C;
    pair<int,int> start;
    pair<int,int> dest;
    fill(&water[0][0], &water[MN-1][MN], INF);
    queue<edge> waterpos;
    for(int i = 0; i < R; i++) {
        cin >> board[i];
        for(int j = 0; j < C; j++) {
            if(board[i][j] == 'S')
                start = {i, j};
            if(board[i][j] == 'D')
                dest = {i, j};
            if(board[i][j] == '*') {
                water[i][j] = 0;
                waterpos.push({i, j, 0});
            }
        }
    }

    //물 움직임
    while(!waterpos.empty()) {
        edge now = waterpos.front(); waterpos.pop();
        int x = now.x;
        int y = now.y;
        int score = now.score;
        for(int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx >= 0 && nx < R && ny >= 0 && ny < C) {
                if(water[nx][ny] != INF) continue;
                if(board[nx][ny] == 'D' || board[nx][ny] == 'X') continue;
                water[nx][ny] = score + 1;
                waterpos.push({nx, ny, score + 1});
            }
        }
    }
        
    edge s;
    s.x = start.first, s.y = start.second, s.score = 0;
    bool visit[MN][MN];
    memset(visit, 0, sizeof(visit));
    visit[s.x][s.y] = true;
    queue<edge> q;
    q.push(s);
    while(!q.empty()) {
        edge now = q.front(); q.pop();
        edge next = now;
        int x = now.x;
        int y = now.y;
        int score = now.score;
        for(int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx >= 0 && nx < R && ny >= 0 && ny < C) {
                if(board[nx][ny] == 'D') {
                    cout << score + 1;
                    return 0;
                }
                if(board[nx][ny] == 'X' || score + 1 >= water[nx][ny] || visit[nx][ny]) continue;
                visit[nx][ny] = true;
                next.x = nx, next.y = ny, next.score = score + 1;
                q.push(next);
            }
        }
    }
    cout << "KAKTUS";
}