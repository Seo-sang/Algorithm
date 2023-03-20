#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;

const int MN = 21;
const int INF = 1e9;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
string board[MN];
int N, M; 
int ans = 11;

void dfs(int x1, int y1, int x2, int y2, int cnt) {

    bool out1 = false, out2 = false;
    if(x1 < 0 || x1 >= N || y1 < 0 || y1 >= M) out1 = true;
    if(x2 < 0 || x2 >= N || y2 < 0 || y2 >= M) out2 = true;

    if(cnt >= ans) return;
    if(cnt > 10) return;
    if(out1 && out2) return;
    if(out1 || out2) {
        ans = min(ans, cnt);
        return;
    }


    for(int d = 0; d < 4; d++) {
        int nx1 = x1 + dx[d];
        int ny1 = y1 + dy[d];
        int nx2 = x2 + dx[d];
        int ny2 = y2 + dy[d];
        if(nx1 >= 0 && nx1 < N && ny1 >= 0 && ny1 < M && board[nx1][ny1] == '#')  {
            nx1 = x1;
            ny1 = y1;
        }
        if(nx2 >= 0 && nx2 < N && ny2 >= 0 && ny2 < M && board[nx2][ny2] == '#')  {
            nx2 = x2;
            ny2 = y2;
        }
        dfs(nx1, ny1, nx2, ny2, cnt + 1);
    }

    return;
}

int main() {
    cin >> N>> M;
    vector<P> coin;
    for(int i = 0; i < N; i++) {
        cin >> board[i];
        for(int j = 0; j < M; j++)
            if(board[i][j] == 'o')
                coin.push_back(make_pair(i, j));
    }

    dfs(coin[0].first, coin[0].second, coin[1].first, coin[1].second, 0);
    if(ans > 10) cout << -1;
    else cout << ans;
    
}