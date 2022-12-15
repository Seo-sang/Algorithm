#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;

const int MN = 201;
const int MK = 1001;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int board[MN][MN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, K; cin >> N >> K;
    vector<pair<int, P>> arr;
    queue<P> q;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
            if(board[i][j] != 0) arr.push_back({board[i][j],{i, j}});
        }
    }
    int S, X, Y; cin >> S >> X >> Y;
    sort(arr.begin(), arr.end());
    for(pair<int, P> e : arr)
        q.push(e.second);
    while(S--) {
        int l = q.size();
        for(int i = 0; i < l; i++) {
            P now = q.front(); q.pop();
            for(int d = 0; d < 4 ;d++) {
                int nx = now.first + dx[d];
                int ny = now.second + dy[d];
                if(nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    if(board[nx][ny] != 0) continue;
                    board[nx][ny] = board[now.first][now.second];
                    q.push({nx, ny});
                }
            }
        }
    }

    cout << board[X-1][Y-1];
}