#include <bits/stdc++.h>

using namespace std;

const int MN = 100001;
const int INF = 1e9;

int color[MN];
int p[MN];
int chk = 0;

void init(int n) {
    for(int i = 1; i <= n; i++) {
        p[i] = i + 1;
    }
}

int update(int n, int b, int x) {
    if(n > b) return n;
    if(color[n] == 0) color[n] = x;
    return p[n] = update(p[n], b, x);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N, Q; cin >> N >> Q;

    init(N);


    while(Q--) {
        int a, b, x; cin >> a >> b >> x;
        update(a, b, x);
    }

    for(int i = 1; i <= N; i++)
        cout << color[i] << ' ';
}