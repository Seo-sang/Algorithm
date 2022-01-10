#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
const int MN = 26;
string board[MN];
bool visit[MN][MN];

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for(int i = 0; i < N; i++)  
        cin >> board[i];

    vector<int> ans;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(visit[i][j] || board[i][j] == '0') continue;
            int cnt = 1;
            visit[i][j] = true;
            queue<pair<int,int>> q;
            q.push({i, j});
            while(!q.empty()) {
                pair<int,int> now = q.front(); q.pop();
                int x = now.first;
                int y = now.second;

                for(int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if(nx >= 0 && nx < N && ny >= 0 && ny < N) {
                        if(visit[nx][ny] || board[nx][ny] == '0') continue;
                        visit[nx][ny] = true;
                        cnt++;
                        q.push({nx, ny});
                    }
                }
            }
            ans.push_back(cnt);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(int e : ans)
        cout << e << '\n';
}