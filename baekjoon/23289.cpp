#include <bits/stdc++.h>
#define P pair<int, int>
using namespace std;
const int MN = 21;

int R, C, K;
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};
int nearx[10] = {0, 0, -1, 1, -1, 1, -1, -1, 1, 1};
int neary[10] = {0, 0, 1, 1, -1, -1, -1, 1, -1, 1};
int board[MN][MN], nxt[MN][MN];
bool vst[MN][MN];
set<P> ver, hor;
map<int, vector<P>> warm;
set<P> inspec;

struct node {
    int x, y, w;
    node(int x, int y, int w) : x(x), y(y), w(w) {}
};

bool nowall(int x, int y, int nx, int ny, int chk, int d) {
    if (chk == 0) {
        if (x == nx) { //가로
            if (hor.find(make_pair(x, min(ny, y))) != hor.end())
                return false;
            else
                return true;
        }
        else { //세로
            if (ver.find(make_pair(max(nx, x), y)) != ver.end())
                return false;
            else
                return true;
        }
    }
    else {
        switch (d) {
        case 1:
        case 2:
            if (ver.find(make_pair(max(x, nx), y)) != ver.end())
                return false;
            if (hor.find(make_pair(nx, min(y, ny))) != hor.end())
                return false;
            break;
        case 3:
        case 4:
            if (ver.find(make_pair(max(nx, x), ny)) != ver.end())
                return false;
            if (hor.find(make_pair(x, min(y, ny))) != hor.end())
                return false;
            break;
        }
        return true;
    }
}

void bfs(int x, int y, int d) {
    memset(vst, 0, sizeof(vst));
    int nx = x + dx[d];
    int ny = y + dy[d];
    queue<node> q;
    if (nx >= 0 && nx < R && ny >= 0 && ny < C && nowall(x, y, nx, ny, 0, d)) {
        q.push(node(nx, ny, 5));
        nxt[nx][ny] += 5;
        vst[nx][ny] = true;
    }
    while (!q.empty())
    {
        node now = q.front();
        q.pop();
        nx = now.x + dx[d];
        ny = now.y + dy[d];
        if (nx >= 0 && nx < R && ny >= 0 && ny < C && !vst[nx][ny] && nowall(now.x, now.y, nx, ny, 0, d))
        {
            vst[nx][ny] = true;
            nxt[nx][ny] += now.w - 1;
            if (now.w > 1)
                q.push(node(nx, ny, now.w - 1));
        }

        nx = now.x + nearx[d * 2];
        ny = now.y + neary[d * 2];
        if (nx >= 0 && nx < R && ny >= 0 && ny < C && !vst[nx][ny] && nowall(now.x, now.y, nx, ny, 1, d))
        {
            vst[nx][ny] = true;
            nxt[nx][ny] += now.w - 1;
            if (now.w > 1)
                q.push(node(nx, ny, now.w - 1));
        }

        nx = now.x + nearx[d * 2 + 1];
        ny = now.y + neary[d * 2 + 1];
        if (nx >= 0 && nx < R && ny >= 0 && ny < C && !vst[nx][ny] && nowall(now.x, now.y, nx, ny, 1, d))
        {
            vst[nx][ny] = true;
            nxt[nx][ny] += now.w - 1;
            if (now.w > 1)
                q.push(node(nx, ny, now.w - 1));
        }
    }
}

void wind()
{
    memcpy(nxt, board, sizeof(nxt));
    for (auto it = warm.begin(); it != warm.end(); it++)
    {
        for (P e : it->second)
        {
            bfs(e.first, e.second, it->first);
        }
    }

    memcpy(board, nxt, sizeof(board));
}

void manipulate()
{
    memcpy(nxt, board, sizeof(nxt));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            // 1, 4
            int nx, ny;
            nx = i + dx[1];
            ny = j + dy[1];
            if (nx >= 0 && nx < R && ny >= 0 && ny < C)
            {
                if (hor.find(make_pair(i, j)) == hor.end())
                {
                    int gap = abs(board[i][j] - board[nx][ny]) / 4;
                    if (board[i][j] > board[nx][ny])
                    {
                        nxt[i][j] -= gap;
                        nxt[nx][ny] += gap;
                    }
                    else
                    {
                        nxt[i][j] += gap;
                        nxt[nx][ny] -= gap;
                    }
                }
            }

            nx = i + dx[4];
            ny = j + dy[4];
            if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
                if (ver.find(make_pair(nx, ny)) == ver.end()) {
                    int gap = abs(board[i][j] - board[nx][ny]) / 4;
                    if (board[i][j] > board[nx][ny]) {
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
    }
    memcpy(board, nxt, sizeof(board));
}

void decrease() {
    for (int i = 0; i < R; i++) {
        if (board[i][0] > 0)
            board[i][0]--;
        if (board[i][C - 1] > 0)
            board[i][C - 1]--;
    }
    for (int i = 1; i < C - 1; i++) {
        if (board[0][i] > 0)
            board[0][i]--;
        if (board[R - 1][i] > 0)
            board[R - 1][i]--;
    }
}

bool check() {
    for (auto it = inspec.begin(); it != inspec.end(); it++)
        if (board[it->first][it->second] < K)
            return false;

    return true;
}

int main() {
    cin >> R >> C >> K;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int a;
            cin >> a;
            if (1 <= a && a <= 4)
                warm[a].push_back(make_pair(i, j));
            else if (a == 5)
                inspec.insert(make_pair(i, j));
        }
    }

    int W;
    cin >> W;
    while (W--) {
        int x, y, t;
        cin >> x >> y >> t;
        x--, y--;
        if (t == 0)
            ver.insert(make_pair(x, y));
        else
            hor.insert(make_pair(x, y));
    }
    int ans = 0;
    while (true) {
        wind();
        manipulate();
        decrease();
        ans++;
        if (ans > 100)
            break;
        if (check())
            break;
    }

    cout << ans;
}