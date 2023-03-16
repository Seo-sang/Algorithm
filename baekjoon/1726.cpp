#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;

const int MN = 101;
const int INF = 1e9;
bool board[MN][MN];
int vst[MN][MN][4];

//동남서북
int dir[5] = {0, 0, 2, 1, 3};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int M, N;

struct node {
    int x, y, d, prev, cnt;
    node() {};
    node(int x, int y, int d, int prev, int cnt) : x(x), y(y), d(d), prev(prev), cnt(cnt) {}
};

queue<node> q;

bool f(int nx, int ny, int nd, int nprev, int ncnt) {
    if(nx >= 0 && nx < M && ny >= 0 && ny < N && !board[nx][ny]) {
        if(vst[nx][ny][nd] > ncnt) {
            q.push(node(nx, ny, nd, nprev, ncnt));
            vst[nx][ny][nd] = ncnt;
        }
    }
    else return false;
    return true;
}

int main() {
    cin >> M >> N;
    
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            cin >> board[i][j];

    node robot; 
    node dest;
    cin >> robot.x >> robot.y >> robot.d;
    cin >> dest.x >> dest.y >> dest.d;
    robot.x--, robot.y--, dest.x--, dest.y--;
    robot.d = dir[robot.d];
    dest.d = dir[dest.d];
    robot.prev = 1;
    robot.cnt = 0;

    fill(&vst[0][0][0], &vst[M-1][N-1][4], INF);

    q.push(robot);
    vst[robot.x][robot.y][robot.d] = 0;
    //go : 0
    //turn left : 1
    //turn right : 2
    while(!q.empty()) {
        node now = q.front(); q.pop();
        int x = now.x;
        int y = now.y;
        int d = now.d;
        int prev = now.prev;
        int cnt = now.cnt;

        switch(prev) {
            case 0:
                //go
                if(f(x + dx[d], y + dy[d], d, 0, cnt + 1))
                    if(f(x + 2 * dx[d], y + 2 * dy[d], d, 0, cnt + 1))
                        f(x + 3 * dx[d], y + 3 * dy[d], d, 0, cnt + 1);
                //turn left
                f(x, y, (d + 3) % 4, 1, cnt + 1);
                //turn right
                f(x, y, (d + 1) % 4, 2, cnt + 1);
                break;
            case 1:
                //go
                if(f(x + dx[d], y + dy[d], d, 0, cnt + 1))
                    if(f(x + 2 * dx[d], y + 2 * dy[d], d, 0, cnt + 1))
                        f(x + 3 * dx[d], y + 3 * dy[d], d, 0, cnt + 1);
                //turn left
                f(x, y, (d + 3) % 4, 1, cnt + 1);
                //turn right
                f(x, y, (d + 1) % 4, 2, cnt + 1);
                break;
            case 2:
                //go
                if(f(x + dx[d], y + dy[d], d, 0, cnt + 1))
                    if(f(x + 2 * dx[d], y + 2 * dy[d], d, 0, cnt + 1))
                        f(x + 3 * dx[d], y + 3 * dy[d], d, 0, cnt + 1);
                //turn left
                f(x, y, (d + 3) % 4, 1, cnt + 1);
                //turn right
                f(x, y, (d + 1) % 4, 2, cnt + 1);
                break;
        }
    }

    cout << vst[dest.x][dest.y][dest.d];
}