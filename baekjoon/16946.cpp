#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

const int MN = 1001;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

string board[MN];
int group[MN][MN];
int cnt[MN * MN];
int idx = 1;


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> board[i];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(group[i][j] || board[i][j] == '1') continue;
            queue<pii> q; q.push(pii(i, j));
            group[i][j] = idx;
            cnt[idx] = 1;
            while(!q.empty()) {
                pii now = q.front(); q.pop();
                for(int d = 0; d < 4; d++) {
                    int nx = now.first + dx[d];
                    int ny = now.second + dy[d];
                    if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                        if(group[nx][ny] || board[nx][ny] == '1') continue;
                        group[nx][ny] = idx;
                        cnt[idx]++;
                        q.push(pii(nx, ny));
                    }
                }
            }
            idx++;
        }
    }


    set<int> vst;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(board[i][j] == '0') {
                cout << 0;
                continue;
            }
            int ans = 1;
            vst.clear();
            for(int d = 0; d < 4; d++) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                    int idx = group[nx][ny];
                    if(vst.find(idx) != vst.end() || board[nx][ny] == '1') continue;
                    vst.insert(idx);
                    ans += cnt[idx];
                    ans %= 10;
                }
            }
            cout << ans;
        }
        cout << '\n';
    }
}