#include <bits/stdc++.h>

using namespace std;
const int MN = 1001;
bool vst[MN];
int child[MN];
vector<int> arr;
vector<int> g[MN];

int main() {
    int N, M; cin >> N >> M;
    while(M--) {
        int num; cin >> num;
        int before;
        cin >> before;
        num--;
        while(num--) {
            int a; cin >> a;
            g[before].push_back(a);
            child[a]++;
            before = a;
        }
    }

    queue<int> q;
    for(int i = 1; i <= N; i++)
        if(child[i] == 0)
            q.push(i);

    while(!q.empty()) {
        int now = q.front(); q.pop();
        arr.push_back(now);
        for(int nxt : g[now]) {
            child[nxt]--;
            if(child[nxt] == 0)
                q.push(nxt);
        }
    }

    if(arr.size() != N) 
        cout << 0;
    else
        for(int e : arr)
            cout << e << '\n';
}