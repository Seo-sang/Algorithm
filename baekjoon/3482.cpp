#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;

const int MN = 1001;
string arr[MN];
bool vst[MN][MN];

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int mcnt = 0;
P start;
int C, R;

void dfs(int x, int y, int cnt) {
    if(mcnt < cnt) {
        mcnt = cnt;
        start = make_pair(x, y);
    }

    for(int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(nx >= 0 && nx < R && ny >= 0 && ny < C) {
            if(vst[nx][ny] || arr[nx][ny] == '#') continue;
            vst[nx][ny] = true;
            dfs(nx, ny, cnt + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int T; cin >> T;
    while(T--) {
        cin >> C >> R;
        
        for(int i = 0; i < R; i++)
            cin >> arr[i];
        
        P s = make_pair(-1, -1);
        
        for(int i = 0; i < R && s.first == -1; i++) {
            for(int j = 0; j < C && s.first == -1; j++) {
                if(arr[i][j] == '.') {
                    s = make_pair(i, j);
                    break;
                }
            }
        }

        mcnt = 0;
        memset(vst, 0, sizeof(vst));
        vst[s.first][s.second] = true;
        dfs(s.first, s.second, 0);

        mcnt = 0;
        memset(vst, 0, sizeof(vst));
        vst[start.first][start.second] = true;
        dfs(start.first, start.second, 0);

        cout << "Maximum rope length is " << mcnt << ".\n";

    }
}