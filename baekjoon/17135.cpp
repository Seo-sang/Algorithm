#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;
const int MN = 16;
int input[MN][MN];
int board[MN][MN];
int dx[3] = {0, -1, 0};
int dy[3] = {-1, 0, 1};
int N, M, D;

int dist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void bfs(int x, int y) {
    queue<P> q;
    q.push(make_pair(x, y));

    while(!q.empty()) {
        for(int d = 0; d < 3; d++) {
            int nx = x + dx[d];
            int ny = p1 + dy[d];
            if(nx >= 0 && nx < x && ny >= 0 && ny <= M) {
                
            }
        }
    }
}

int simul(int p1, int p2, int p3) {
    memcpy(board, input, sizeof(board));
    int ret = 0;
    for(int x = N; x >= 0; x--) {
        bfs(x, p1);
        bfs(x, p2);
        bfs(x, p3);
    }

    return ret;
}

int main() {
    cin >> N >> M >> D;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> input[i][j];

    for(int i = 0; i < M - 2; i++)
        for(int j = i + 1; j < M - 1; j++)
            for(int k = j + 1; k < M; k++)
                simul(i, j, k);
}