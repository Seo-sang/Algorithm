#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;
const int MN = 1001;
const int INF = 1e9;
string board[MN];
int fire[MN][MN];
bool vst[MN][MN];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

struct node {
    int x, y, w;
    node(int x, int y, int w) : x(x), y(y), w(w) {}
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int T; cin >> T;
    while(T--) {
        int W, H; cin >> W >> H;
        memset(fire, -1, sizeof(fire));
        fill(&fire[0][0], &fire[MN - 1][MN], INF);
        memset(vst, 0, sizeof(vst));
        queue<node> q;
        P sang;
        for(int i = 0; i < H; i++) {
            cin >> board[i];
            for(int j = 0; j < W; j++) {
                if(board[i][j] == '*') {
                    fire[i][j] = 0;
                    q.push(node(i, j, 0));
                }
                else if(board[i][j] == '@') sang = make_pair(i, j);
            }
        }
        if(sang.first == 0 || sang.first == H - 1 || sang.second == 0 || sang.second == W - 1) {
            cout << "1\n";
            continue;
        }
        //불번짐
        while(!q.empty()) {
            node now = q.front(); q.pop();
            for(int d = 0; d < 4; d++) {
                int nx = now.x + dx[d];
                int ny = now.y + dy[d];
                if(nx >= 0 && nx < H && ny >= 0 && ny < W) {
                    if(fire[nx][ny] != INF || board[nx][ny] == '#') continue;
                    fire[nx][ny] = now.w + 1;
                    q.push(node(nx, ny, now.w + 1));
                }
            }
        }
        q.push(node(sang.first, sang.second, 0));
        vst[sang.first][sang.second] = true;
        int ans = INF;
        while(!q.empty()) {
            node now = q.front(); q.pop();
            for(int d = 0; d < 4; d++) {
                int nx = now.x + dx[d];
                int ny = now.y + dy[d];
                if(nx >= 0 && nx < H && ny >= 0 && ny < W) {
                    if(board[nx][ny] == '#' || vst[nx][ny] || fire[nx][ny] <= now.w + 1) continue;
                    vst[nx][ny] = true;
                    if(nx == 0 || nx == H-1 || ny == 0 || ny == W-1) {
                        ans = min(ans, now.w + 2);
                        break;
                    }
                    q.push(node(nx, ny, now.w + 1));
                }
            }
        }
        if(ans == INF) cout << "IMPOSSIBLE\n";
        else cout << ans << '\n';
    }
}