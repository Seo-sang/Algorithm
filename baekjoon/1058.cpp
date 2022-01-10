#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MN = 51;
string board[MN];
bool visit[MN];
vector<int> g[MN];

int main() {{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int ans = 0, cnt;
    int N; cin >> N;
    for(int i = 0; i < N; i++)
        cin >> board[i];

    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(board[i][j] == 'Y') {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    for(int i = 0; i < N; i++) {
        cnt = 0;
        memset(visit, 0, sizeof(visit));
        visit[i] = true;
        queue<int> q;
        for(int e : g[i]) {
            q.push(e);
            cnt++;
            visit[e] = true;
        }

        while(!q.empty()) {
            int now = q.front(); q.pop();
            for(int e : g[now]) {
                if(visit[e]) continue;
                visit[e] = true;
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }

    cout << ans;
}