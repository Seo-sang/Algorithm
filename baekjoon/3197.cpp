#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int R, C;
const int MN = 1501;
const int INF = 1e9;
string board[MN];
int num[MN][MN];

struct node {
    int x, y, depth;
    node(int x, int y, int depth) : x(x), y(y), depth(depth) {}
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> R >> C;
    P swan;
    fill(&num[0][0], &num[R-1][C], INF);
    for(int i = 0; i < R; i++) {
        cin >> board[i];
        for(int j = 0; j < C; j++) {
            if(board[i][j] == 'L') {
                swan = make_pair(i, j);
            }
        }
    }
    queue<node> q; q.push(node(swan.first, swan.second, 0));
    num[swan.first][swan.second] = 0;
    while(!q.empty()) {
        node now = q.front(); q.pop();
        for(int d = 0; d < 4; d++) {
            int nx = now.x + dx[d];
            int ny = now.y + dy[d];
            if(nx >= 0 && nx < R && ny >= 0 && ny < C) {
                if(board[nx][ny] == 'L') {

                }
                else if(board[nx][ny] == '.' || board[nx][ny] == 'L') {
                    if(num[nx][ny] > num[now.x][now.y] + ((now.depth + 1) / 2)) {
                        num[nx][ny] = num[now.x][now.y] + ((now.depth + 1) / 2);
                        q.push(node(nx, ny, 0));
                    }
                }
            }
        }
    }
}