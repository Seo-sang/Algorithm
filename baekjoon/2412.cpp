#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

map<pii, bool> m;
int N, T;

struct node {
    int x, y, cnt;
    node(int x, int y, int cnt) : x(x), y(y), cnt(cnt) {}
};

int f() {
    queue<node> q; q.push(node(0, 0, 0));
    while(!q.empty()) {
        node now = q.front(); q.pop();
        for(int i = -2; i <= 2; i++) {
            for(int j = -2; j <= 2; j++) {
                int nx = now.x + i;
                int ny = now.y + j;
                if(m.find(pii(nx, ny)) == m.end() || m[pii(nx, ny)] == true) continue;
                if(ny == T) return now.cnt + 1;
                m[pii(nx, ny)] = 1;
                q.push(node(nx, ny, now.cnt + 1));
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> N >> T;
    for(int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        m[pii(a, b)] = false;
    }
    cout << f();
}