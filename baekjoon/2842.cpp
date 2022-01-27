#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;
const int MN = 51;
string arr[MN];
int high[MN][MN];
set<int> s;
bool visited[MN][MN];
int N;
int home = 0;
int cnt;
int dx[8] = {1, 0, 0, -1, 1, 1, -1, -1};
int dy[8] = {0, 1, -1, 0, 1, -1, 1, -1};

void dfs(int x, int y, int up, int down) {
    for(int d = 0; d < 8; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(nx >= 0 && nx < N && ny >= 0 && ny < N) {
            if(visited[nx][ny] || up < high[nx][ny] || down > high[nx][ny]) continue;
            visited[nx][ny] = true;
            if(arr[nx][ny] == 'K') cnt++;
            if(cnt == home) return;
            dfs(nx,ny, up, down);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    P start;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        for(int j = 0; j < N; j++) {
            if(arr[i][j] == 'P') {
                start.first = i;
                start.second = j;
            }
            else if(arr[i][j] == 'K') home++;
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> high[i][j];
            s.insert(high[i][j]);
        }
    }
    auto left = s.begin();
    auto right = s.begin();
    int ans = 1e9;
    while(right != s.end()) {
        while(left != s.end()) {
            memset(visited, 0, sizeof(visited));
            cnt = 0;
            if(high[start.first][start.second] < *left || high[start.first][start.second] > *right) break;
            visited[start.first][start.second] = true;
            dfs(start.first, start.second, *right, *left);
            if(cnt != home) break;
            ans = min(ans, *right - *left);
            left++;
        }
        right++;
    }

    cout << ans;
}