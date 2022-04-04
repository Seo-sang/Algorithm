#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;

const int MN = 101;
string board[MN];
string nxt[MN];
bool vst[MN][MN];
int bot[MN];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int R, C;

void LtoR(int level) {
    for(int i = 0; i < C; i++) {
        if(board[level][i] == 'x') {
            board[level][i] = '.';
            break;
        }
    }
}

void RtoL(int level) {
    for(int i = C - 1; i >= 0; i--) {
        if(board[level][i] == 'x') {
            board[level][i] = '.';
            break;
        }
    }
}

bool cmp(P a, P b) {
    return a.first > b.first;
}

void drop() {
    memset(vst, 0, sizeof(vst));
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(board[i][j] == '.' || vst[i][j]) continue;
            memset(bot, -1, sizeof(bot));
            bool above = true;
            vst[i][j] = true;
            vector<P> v;
            queue<P> q;
            q.push(make_pair(i, j));
            v.push_back(make_pair(i, j));
            //cout << "-----------------\n";
            //cout << i << ' ' << j << ' ' << board[i][j] << endl;
            while(!q.empty()) {
                P now = q.front(); q.pop();
                bot[now.second] = max(bot[now.second], now.first);
                for(int d = 0; d < 4; d++) {
                    int nx = now.first + dx[d];
                    int ny = now.second + dy[d];

                    if(nx >= 0 && nx < R && ny >= 0 && ny < C) {
                        if(board[nx][ny] == '.' || vst[nx][ny]) continue;
                        vst[nx][ny] = true;
                        v.push_back(make_pair(nx, ny));
                        //cout << nx << ' ' << ny << endl;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
            int depth = MN;
            for(int c = 0; c < C; c++) {
                if(bot[c] == -1) continue;
                int idx = bot[c] + 1;
                if(idx >= R) { //바닥과 닿는 경우
                    above = false;
                    break;
                }
                int tmp = 0;
                while(idx < R && board[idx][c] =='.') {
                    tmp++;
                    idx++;
                }
                depth = min(depth, tmp);
            }
            if(above) {
                //cout <<"above : " << i << ' ' << j << '\n';
                sort(v.begin(), v.end(), cmp);
                for(P e : v) {
                    //cout << e.first << ' ' << e.second << '\n';
                    board[e.first + depth][e.second] = 'x';
                    board[e.first][e.second] = '.';
                    vst[e.first+ depth][e.second] = true;
                }
                return;
            }
        }
    }
}

void print() {
    for(int i = 0; i < R; i++)
        cout << board[i] << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> R >> C;
    for(int i = 0; i < R; i++)
        cin >> board[i];

    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        int high; cin >> high; high = R - high;
        if(i % 2 == 0) LtoR(high);
        else RtoL(high);
        drop();
    }

    print();
}