#include <bits/stdc++.h>

using namespace std;

const int MN = 100001;
int p[MN];

int find(int n) {
    if(p[n] == n) return n;
    return p[n] = find(p[n]);
}

int main() {
    int N, M; cin >> N >> M;

    for(int i = 1; i <= N; i++) p[i] = i;


    int cnt = 0;
    while(M--) {
        int u, v; cin >> u >> v;
        int pu = find(u);
        int pv = find(v);
        if(pu != pv) {
            p[pu] = pv;
        }
        else {
            cnt++;
        }
    }

    set<int> s;
    for(int i = 1; i <= N; i++)
        s.insert(find(i));

    cout << cnt + s.size() - 1;
}