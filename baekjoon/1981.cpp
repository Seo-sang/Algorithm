#include <bits/stdc++.h>

using namespace std;
const int MN = 101;
int arr[MN][MN];

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
set<int> s;
bool visited[MN][MN];
bool chk;
int N;

void dfs(int x, int y, int left, int right) {
    for(int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(nx >= 0 && nx < N && ny >= 0 && ny < N) {
            if(visited[nx][ny] || arr[nx][ny] < left || right < arr[nx][ny]) continue;
            visited[nx][ny] = true;
            if((nx == N - 1) && (ny == N - 1)) chk = true;
            if(chk) return;
            dfs(nx ,ny, left, right);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
            s.insert(arr[i][j]);
        }
    }

    auto left = s.begin(), right = s.begin();
    int ans = 1e9;
    while(right != s.end()) {
        while(left != s.end()) {
            memset(visited, 0, sizeof(visited));
            chk = false;
            if(arr[0][0] > *right || arr[0][0] < *left) break;
            visited[0][0] = true;
            dfs(0, 0, *left, *right);
            if(!chk) break;
            ans = min(ans, *right - *left);
            left++;
        }
        right++;
    }

    cout << ans;
}