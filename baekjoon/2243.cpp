#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int MN = 1000001;
int seg[MN * 3];
int ans;

int update(int node, int start, int end, int idx, int amount) {
    if(idx < start || end < idx) return seg[node];
    if(start == end) return seg[node] += amount;

    int mid = (start + end) / 2;
    return seg[node] = update(node * 2, start, mid, idx, amount) + update(node * 2 + 1, mid + 1, end, idx, amount);
}

int query(int node, int start, int end, int pos) {
    if(pos < 1 || pos > seg[node]) return seg[node];
    if(start == end) {
        if(ans) return seg[node];
        ans = start;
        seg[node]--;
        return seg[node];
    }
    int mid = (start + end) / 2;
    return seg[node] = query(node * 2, start, mid, pos) + query(node * 2 + 1, mid + 1, end, pos - seg[node * 2]);
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;

    while(N--) {
        int A, B, C; cin >> A;
        ans = 0;
        if(A == 1) {
            cin >> B;
            query(1, 0, MN - 1, B);
            cout << ans << '\n';
        }
        else {
            cin >> B >> C;
            update(1, 0, MN - 1, B, C);
        }
    }
}