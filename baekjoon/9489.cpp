#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;
const int MN = 1001;
vector<vector<int> > arr;
vector<int> g[MN];
int pos;

int dfs(int now, int prev) {
}

int main() {
    int N, K;
    while(true) {
        cin >> N >> K;
        if(N == 0 && K == 0) break;
        arr.clear();
        for(int i = 0; i <= N; i++)
            g[i].clear();
        int before, now;
        pos = 0;
        for(int i = 0; i < N; i++) {
            cin >> now;
            if(i != 0) {
                if(before + 1 < now) {
                    arr.push_back(vector<int>(1, now));
                }
                else {
                    arr.back().push_back(now);
                }
            }
            else {
                idx = now;
            }

            before = now;
        }
        queue<P> q; q.push(make_pair(idx, 0));
        int level;
        while(!q.empty()) {
            P n = q.front(); q.pop();
            for(int e : arr[pos]) {
                g[n.first].push_back(e);
                q.push(make_pair(e, n.second + 1));
                if(e == K) level = n.second + 1;
            }
            pos++;
        }
        dfs(idx);
    }
}