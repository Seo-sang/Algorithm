#include <bits/stdc++.h>

using namespace std;
const int MN = 200001;

int par[MN];
int p[MN];
struct edge {
    int x, b, c, d;
};
vector<edge> query;
vector<bool> rst;

void init(int n) {
    for(int i = 1; i <= n; i++)
        p[i] = i;
}

int find(int x) {
    if(x == p[x]) return x;
    return p[x] = find(p[x]);
}

void unite(int x, int y) {
    x = find(x), y = find(y);
    p[y]= x;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, Q; cin >> N >> Q;
    init(N);
    for(int i = 0; i < N - 1; i++)
        cin >> par[i + 2];
        
    Q += (N - 1);
    while(Q--) {
        int x, b, c, d; cin >> x;
        if(x == 0) {
            cin >> b;
            edge e = {x, b, 0, 0};
            query.push_back(e);
        }
        else {
            cin >> c >> d;
            edge e = {x, 0, c, d};
            query.push_back(e);
        }
    }

    reverse(query.begin(), query.end());

    for(edge q : query) {
        if(q.x == 0)
            unite(q.b, par[q.b]);
        else {
            if(find(q.c) != find(q.d))
                rst.push_back(0);
            else
                rst.push_back(1);
        }
    }
    for(auto it = rst.rbegin(); it != rst.rend(); it++) {
        if(*it)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}