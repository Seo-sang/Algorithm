#include <bits/stdc++.h>

using namespace std;

const int MN = (2 << 20) + 1;
bool tree[MN];

int search(int now) {
    int ret = 0;
    if(now == 1) return 0;
    if(tree[now]) ret = now;
    int tmp = search(now / 2);
    if(tmp) ret = tmp;

    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, Q; cin >> N>> Q;
    while(Q--) {
        int x; cin >> x;
        cout << search(x) << '\n';
        tree[x] = true;
    }
}