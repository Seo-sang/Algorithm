#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MN = 10001;
vector<int> g[MN];
bool visit[MN];
int degree[MN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
        
    for(int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        g[b].push_back(a);
    }
    int mnum = 0;
    for(int i = 1; i <= N; i++) {
        memset(visit, 0, sizeof(visit));
        visit[i] = true;
        queue<int> q;
        q.push(i);
        while(!q.empty()) {
            int now = q.front(); q.pop();
            for(int e : g[now]) {
                if(visit[e]) continue;
                visit[e] = true;
                q.push(e);
                degree[i]++;
                mnum = max(mnum, degree[i]);
            }
        }
    }

    vector<int> ans;
    for(int i = 1; i <= N; i++)
        if(degree[i] == mnum)
            ans.push_back(i);

    for(int e : ans)
        cout << e << ' ';
}