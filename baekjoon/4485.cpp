#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int MN = 126;
const int INF = 1e9;

int board[MN][MN];
bool visit[MN][MN];

struct edge{
    int w, x, y;
};

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

struct cmp{
    bool operator() (edge a, edge b) {
        return a.w > b.w;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T = 0;
    while(true) {
        T++;
        int N; cin >> N;
        if(N == 0) break;
        memset(board, 0, sizeof(board));
        memset(visit, 0, sizeof(visit));
        int ans = -1;
        for(int i = 0; i< N; i++)
            for(int j = 0; j < N; j++)
                cin >> board[i][j];

        priority_queue<edge, vector<edge>, cmp> pq;
        pq.push({board[0][0], 0, 0});
        visit[0][0] = true;
        while(!pq.empty() && ans == -1) {
            edge now = pq.top(); pq.pop();
            for(int d = 0; d < 4; d++) {
                int nx = now.x + dx[d];
                int ny = now.y + dy[d];
                if(nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    if(visit[nx][ny]) continue;
                    visit[nx][ny] = true;
                    if(nx == N-1 && ny == N-1) {
                        ans = board[nx][ny] + now.w;
                        break;
                    }
                    pq.push({board[nx][ny] + now.w, nx, ny});
                }
            }
        }
        cout << "Problem " << T <<": " << ans << '\n';
    }
}