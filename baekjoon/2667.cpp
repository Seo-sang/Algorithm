#include <bits/stdc++.h>

using namespace std;
const int MN = 26;
string board[MN];
bool vst[MN][MN];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
vector<int> v;
int N;

int dfs(int x, int y) {
    int ret = 1;
    for(int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(nx >= 0 && nx < N && ny >= 0 && ny < N) {
            if(vst[nx][ny] == false && board[nx][ny] == '1') {
                vst[nx][ny] = true;
                ret += dfs(nx, ny);
            }
        }
    }

    return ret;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> board[i];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(board[i][j] == '1' && vst[i][j] == false) {
                vst[i][j] = true;
                v.push_back(dfs(i, j));
            }
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for(int e : v)
        cout << e << '\n';
}