#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MN = 1e6;
vector<int> g[MN + 1];

//0는 아님, 1은 얼리어답터
int visit[MN + 1][2];

int dfs(int n, int early, int parent) {
    if(visit[n][early]) return visit[n][early];
    int ret = early;
    for(int e : g[n]) {
        if(e == parent) continue;
        if(early) {
            int tmp = dfs(e, 0, n);
            ret += min(tmp, dfs(e, 1, n));
        }
        else {
            ret += dfs(e, 1, n);
        }
    }

    return visit[n][early] = ret;
}

int main() {
    int N; cin >> N;
    int mlevel = 0;
    for(int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    cout << min(dfs(1, 0, 0), dfs(1, 1, 0));
}