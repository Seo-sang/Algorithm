#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;
const int MN = 21;

int R, C, K;
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};
int nearx[10] = {0, 0, -1, 1, -1, 1, -1, -1, 1, 1};
int neary[10] = {0, 0, 1, 1, -1, -1, -1, 1, -1, 1};
int board[MN][MN], nxt[MN][MN];
bool wall[MN][MN], vst[MN][MN];
map<int, vector<P>> warm;
set<P> inspec;

struct node {
    int x, y, w;
};

void bfs(int x, int y, int d) {
    memset(vst, 0, sizeof(vst));
    queue<node> q; q.push({x, y, 6});
    vst[x][y] = true;
    while(!q.empty()) {
        node now = q.front(); q.pop();
        int nx, ny;
        nx = now.x + dx[d];
        ny = now.y + dy[d];
        if(nx >= 0 && nx < R && ny >= 0 && ny <  C && !vst[nx][ny] && !(wall[x][y] && wall[nx][ny])) {
            vst[nx][ny] = true;
            nxt[nx][ny] += now.w - 1;
            if(now.w > 0)
                q.push({nx, ny, now.w - 1});
        }
        
        nx = now.x + nearx[d * 2];
        ny = now.y + neary[d * 2];
        if(nx >= 0 && nx < R && ny >= 0 && ny <  C && !vst[nx][ny]) {
            vst[nx][ny] = true;
            nxt[nx][ny] += now.w - 1;
            if(now.w > 0)
                q.push({nx, ny, now.w - 1});
        }

        nx = now.x + nearx[d * 2 + 1];
        ny = now.y + neary[d * 2 + 1];
        if(nx >= 0 && nx < R && ny >= 0 && ny <  C && !vst[nx][ny]) {
            vst[nx][ny] = true;
            nxt[nx][ny] += now.w - 1;
            if(now.w > 0)
                q.push({nx, ny, now.w - 1});
        }
    }
}

void wind() {
    memcpy(nxt, board, sizeof(nxt));
    for(auto it = warm.begin(); it != warm.end(); it++)
        for(P e : it->second)
            bfs(e.first, e.second, it->first);

    memcpy(board, nxt, sizeof(board));
}

void manipulate() {
    memcpy(nxt, board, sizeof(nxt));
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            //1, 4
            int nx, ny;
            nx = i + dx[1];
            ny = j + dy[1];
            if(!wall[i][j] || !wall[nx][ny]) {
                int gap = abs(board[i][j] - board[nx][ny]) / 4;
                if(board[i][j] > board[nx][ny]) {
                    nxt[i][j] -= gap;
                    nxt[nx][ny] += gap;
                }
                else {
                    nxt[i][j] += gap;
                    nxt[nx][ny] -= gap;
                }
            }
            
            nx = i + dx[4];
            ny = j + dy[4];
            if(!wall[i][j] || !wall[nx][ny]) {
                int gap = abs(board[i][j] - board[nx][ny]);
                if(board[i][j] > board[nx][ny]) {
                    nxt[i][j] -= gap;
                    nxt[nx][ny] += gap;
                }
                else {
                    nxt[i][j] += gap;
                    nxt[nx][ny] -= gap;
                }
            }
        }
    }
    memcpy(board, nxt, sizeof(board));
}

void decrease() {
    for(int i = 0; i < R; i++) {
        if(board[i][0] > 0) board[i][0]--;
        if(board[i][C-1] > 0) board[i][C-1]--;
    }
    for(int i = 0; i < C; i++) {
        if(board[0][i] > 0) board[0][i]--;
        if(board[R - 1][i] > 0) board[R - 1][i]--;
    }
}

bool check() {
    for(auto it = inspec.begin(); it != inspec.end(); it++)
        if(board[it->first][it->second] < K) return false;

    return true;
}

void print() {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++)
            cout << board[i][j] << ' ';
        cout << endl;
    }
}

int main() {
    cin >> R >> C >> K;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            int a; cin >> a;
            if(1 <= a && a <= 4) warm[a].push_back({i, j});
            else if(a == 5) inspec.insert({i, j});
        }
    }

    int W; cin >> W;
    while(W--) {
        int x, y, t; cin >> x >> y >> t;
        if(t == 0)
            wall[x-1][y] = true;
        else
            wall[x][y+1]= true;
        wall[x][y] = true;
    }
    int ans = 0;
    while(true) {
        wind();
        manipulate();
        decrease();
        ans++;
        print();
        cout << endl;
        if(check()) break;
    }
    cout << ans;
}