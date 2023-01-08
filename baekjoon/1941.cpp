#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;

const int MN = 5;

string board[MN];
bool vst[MN][MN];

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

set<set<P>> ans;

void dfs(int S, int Y, set<P> s) {
    if(S + Y == 7) {
        ans.insert(s);
        return;
    }
    for(auto it = s.begin(); it != s.end(); it++) {
        int x = it->first;
        int y = it->second;
        for(int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
                if(vst[nx][ny]) continue;
                int nS = S, nY = Y;
                if(board[nx][ny] == 'S') nS++;
                else nY++;
                if(nY > 3) continue;
                vst[nx][ny] = true;
                s.insert(make_pair(nx, ny));
                dfs(nS, nY, s);
                s.erase(make_pair(nx, ny));
                vst[nx][ny] = false;
            }
        }
    }
}

int main() {
    for(int i = 0; i < 5; i++)
        cin >> board[i];

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(board[i][j] == 'Y') continue;
            memset(vst, 0, sizeof(vst));
            vst[i][j] = true;
            set<P> s;
            s.insert(make_pair(i, j));
            dfs(1, 0, s);
            vst[i][j] = false;
        }
    }
    cout << ans.size();
}