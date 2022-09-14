#include <bits/stdc++.h>

using namespace std;
const int MN = 500001;
int seg[MN * 3];
int N, M; 

int update(int n, int left, int right, int value, int pos) {
    if(left == right) return seg[n] += value;
    int mid = (left + right) / 2;
    if(pos <= mid) return seg[n] = update(n * 2, left, mid, value, pos) + seg[n * 2 + 1];
    else return seg[n] = seg[n * 2] + update(n * 2 + 1, mid + 1, right, value, pos);
}

int query(int n, int left, int right, int value) {
    if(left == right) return left;
    int mid = (left + right) / 2;
    if(value <= seg[n * 2]) return query(n * 2, left, mid, value);
    else return query(n * 2 + 1, mid + 1, right, value - seg[n * 2]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        int a; cin >> a;
        update(1, 1, N, a, i);
    }
    cin >> M;
    while(M--) {
        int a, b, c;
        cin >> a;
        if(a == 1) {
            cin >> b >> c;
            update(1, 1, N, c, b);
        }
        else {
            cin >> b;
            cout << query(1, 1, N, b) << '\n';
        }
    }
}