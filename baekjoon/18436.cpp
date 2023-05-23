#include <bits/stdc++.h>

using namespace std;

const int MN = 100001;

int odd[MN * 3], even[MN * 3];

void update(int node, int left, int right, int pos, int value) {
    if(pos < left || right < pos) return;
    if(left == right) {
        if(value % 2) {
            odd[node] = 1;
            even[node] = 0;
        }
        else {
            odd[node] = 0;
            even[node] = 1;
        }
        return;
    }
    int mid = (left + right) / 2;
    update(node * 2, left, mid, pos, value);
    update(node * 2 + 1, mid + 1, right, pos, value);

    odd[node] = odd[node * 2] + odd[node * 2 + 1];
    even[node] = even[node * 2] + even[node * 2 + 1];
}

int query(int node, int left, int right, int start, int end, bool chk) {
    if(right < start || end < left) return 0;

    if(start <= left && right <= end) {
        if(chk) return odd[node];
        else return even[node];
    }

    int mid = (left + right) / 2;

    return query(node * 2, left, mid, start, end, chk) + query(node * 2 + 1, mid + 1, right, start, end, chk);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        int a; cin >> a;
        update(1, 1, N, i, a);
    }

    int M; cin >> M;
    while(M--) {
        int a, b, c; cin >> a >> b >> c;
        if(a == 1) update(1, 1, N, b, c);
        else if(a == 2) cout << query(1, 1, N, b, c, 0) << '\n';
        else cout << query(1, 1, N, b, c, 1) << '\n';
    }
}