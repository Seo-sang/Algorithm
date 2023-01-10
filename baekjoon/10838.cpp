#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;

const int MN = 100001;
bool vst[MN];
int parent[MN];
int color[MN];
set<int> ans;

int find(int a, int b) {
    if(a == b) return a;
    if(a != -1 && vst[a]) return a;
    if(b != -1 && vst[b]) return b;
    if(a != -1)
        vst[a] = true;
    if(b != -1)
        vst[b] = true;
    if(a == -1)
        return find(-1, parent[b]);
    else if(b == -1)
        return find(parent[a], -1);
    else
        return find(parent[a], parent[b]);
}

void paint(int ancestor, int a, int b, int c) {
    if(a == b) return;
    int na = a, nb = b;
    if(ancestor != a) {
        color[a] = c;
        na = parent[a];
    }
    if(ancestor != b) {
        color[b] = c;
        nb = parent[b];
    }

    paint(ancestor, na, nb, c);
}

void count(int ancestor, int a, int b) {
    if(a == b) return;
    int na = a, nb = b;
    if(ancestor != a) {
        ans.insert(color[a]);
        na = parent[a];
    }
    if(ancestor != b) {
        ans.insert(color[b]);
        nb = parent[b];
    }

    count(ancestor, na, nb);
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, K; cin >> N >> K;
    for(int i = 0; i < N; i++)
        parent[i] = 0;
    parent[0] = -1;
    while(K--) {
        int r, a, b, c; cin >> r;
        if(r == 1) {
            cin >> a >> b >> c;
            memset(vst, 0, sizeof(vst));
            int ancestor = find(a, b);
            paint(ancestor, a, b, c);
        }
        else if(r == 2) {
            cin >> a >> b;
            parent[a] = b;
        }
        else {
            cin >> a >> b;
            memset(vst, 0, sizeof(vst));
            int ancestor = find(a, b);
            ans.clear();
            count(ancestor, a, b);
            cout << ans.size() << '\n';
        }
    }
}