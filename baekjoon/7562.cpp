#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int MN = 301;
bool visit[MN][MN];

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

struct edge {
    int x, y, w;
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while(T--) {
        int I; cin >> I;
        pair<int,int> dept, dest;
        cin >> dept.first >> dept.second;
        cin >> dest.first >> dest.second;
        if(dept.first == dest.first && dept.second == dest.second) {
            cout << 0 <<'\n';
            continue;
        }
        memset(visit, 0, sizeof(visit));
        queue<edge> q;
        q.push({dept.first, dept.second, 0});
        visit[dept.first][dept.second] = true;
        int ans = 0;
        while(!q.empty() && ans == 0) {
            edge now = q.front(); q.pop();

            for(int d = 0; d < 8; d++) {
                int nx = now.x + dx[d];
                int ny = now.y + dy[d];
                if(nx >= 0 && nx < I && ny >= 0 && ny < I) {
                    if(visit[nx][ny]) continue;
                    visit[nx][ny] = true;
                    if(nx == dest.first && ny == dest.second) {
                        ans = now.w + 1;
                        break;
                    }
                    q.push({nx, ny, now.w + 1});
                }
            }
        }
        cout << ans << '\n';
    }
}