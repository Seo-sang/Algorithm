#include <bits/stdc++.h>

using namespace std;
const int MN = 102;
const int INF = 1e9;
struct shark {
    int x, y, z;
};
vector<shark> arr;
vector<int> g[MN];
int p[MN];
bool visited[MN];

int dfs(int n) {
    for(int nxt : g[n]) {
        if(visited[nxt]) continue;
        visited[nxt] = true;
        if(p[nxt] == -1 || dfs(p[nxt])) {
            p[nxt] = n;
            return 1;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    shark tmp = {0, 0, 0};
    arr.push_back(tmp);
    memset(p, -1, sizeof(p));
    for(int i = 1; i <= N; i++) {
        int x, y, z; cin >> x >> y >> z;
        shark input = {x, y, z};
        arr.push_back(input);
        for(int j = 1; j < i; j++) {
            shark now = arr[j];
            if(x >= now.x && y >= now.y && z >= now.z) {
                g[i].push_back(j + 50);
            }
            else if(x <= now.x && y <= now.y && z <= now.z) {
                g[j].push_back(i + 50);
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < 2; j++) {
            memset(visited, 0, sizeof(visited));
            dfs(i);
        }
    }

    int ans = 0;
    for(int i = 51; i <= N + 50; i++) {
        if(p[i] == -1) ans++;
    }

    cout << ans;
}