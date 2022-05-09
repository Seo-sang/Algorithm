#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;
const int MN = 12;
string board[MN];
bool boom[MN][6], vst[MN][6];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int main() {
    for(int i = 0; i < MN; i++)
        cin >> board[i];
    bool chk = true;
    int ans = 0;
    while(chk) {
        chk = false;
        memset(boom, 0, sizeof(boom));
        //터질거 확인
        for(int i = 0; i < MN; i++) {
            for(int j = 0; j < 6; j++) {
                if(board[i][j] == '.' || boom[i][j]) continue;
                queue<P> q; q.push(make_pair(i, j));
                int cnt = 1;
                memset(vst, 0, sizeof(vst));
                vst[i][j] = true;
                while(!q.empty()) {
                    P now = q.front(); q.pop();
                    for(int d = 0; d < 4; d++) {
                        int nx = now.first + dx[d];
                        int ny = now.second + dy[d];
                        if(nx >= 0 && nx < 12 && ny >= 0 && ny < 6) {
                            if(vst[nx][ny] || board[nx][ny] != board[i][j]) continue;
                            vst[nx][ny] = true;
                            cnt++;
                            q.push(make_pair(nx, ny));
                        }
                    }
                }
                if(cnt > 3) {
                    chk = true;
                    for(int x = 0; x < 12; x++)
                        for(int y = 0; y < 6; y++)
                            boom[x][y] = boom[x][y] || vst[x][y];
                }
            }
        }
        if(!chk) break;
        ans++;
        //터짐
        for(int x = 0; x < 12; x++)
            for(int y = 0; y < 6; y++)
                if(boom[x][y]) board[x][y] = '.';

        //떨어짐
        for(int y = 0; y < 6; y++) {
            for(int x = 11; x >= 0; x--) {
                if(board[x][y] != '.') continue;
                int now = x - 1;
                while(now >= 0 && board[now][y] == '.')
                    now--;
                if(now >= 0) {
                    board[x][y] = board[now][y];
                    board[now][y] = '.';
                }
            }
        }
    }
    cout << ans;
}