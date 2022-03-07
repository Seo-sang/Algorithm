#include <bits/stdc++.h>

using namespace std;
const int MN = 300001;
string dict[MN];
bool vst[4][4];
bool cnt[MN];
string board[4];
int score[9] = {0, 0, 0, 1, 1, 2, 3, 5, 11};
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {0, 1, -1, 1, -1, 0, 1, -1};
int mnum, num;
string ans;

void dfs(int x, int y, string s, int idx) {
    if(s == dict[idx]) {
        if(!cnt[idx]) {
            num++;
            mnum += score[s.size()];
        }
        cnt[idx] = true;
        if(ans.size() < s.size()) ans = s;
        return;
    }

    for(int d = 0; d < 8; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(nx >= 0 && nx < 4 && ny >= 0 && ny < 4) {
            if(vst[nx][ny]) continue;
            if(board[nx][ny] == dict[idx][s.size()]) {
                vst[nx][ny] = true;
                s += board[nx][ny];
                dfs(nx, ny, s, idx);
                s = s.substr(0, s.size() - 1);
                vst[nx][ny] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int W; cin >> W;

    for(int i = 0;  i< W; i++)
        cin >> dict[i];
    sort(dict, dict + W);
    int B; cin >> B;
    while(B--) {
        for(int i = 0; i < 4; i++)
            cin >> board[i];
        ans = "";
        mnum = 0, num = 0;
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < W; i++) {
            for(int x = 0; x < 4; x++) {
                for(int y = 0; y < 4; y++) {
                    if(board[x][y] == dict[i][0]) {
                        memset(vst, 0, sizeof(vst));
                        vst[x][y] = true;
                        dfs(x, y, dict[i].substr(0, 1), i);
                    }
                }
            }
        }
        cout << mnum << ' ' << ans << ' ' << num << '\n';
    }
}