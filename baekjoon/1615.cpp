#include <bits/stdc++.h>
#define pii pair<int,int>
#define ll long long

using namespace std;
const int MN = 2001;
ll seg[MN * 4];
vector<pii> arr;

void update(int node, int left, int right, int pos) {
    if(pos < left || right < pos) return;
    if(left == right) {
        seg[node]++;
        return;
    }
    int mid = (left + right) / 2;
    update(node * 2, left, mid, pos);
    update(node * 2 + 1, mid + 1, right, pos);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

ll query(int node, int left, int right, int start, int end) {
    if(end < left || right < start) return 0;
    if(start <= left && right <= end) return seg[node];
    int mid = (left + right) / 2;
    return query(node * 2, left, mid, start, end) + query(node * 2 + 1, mid + 1, right, start, end);
}

void print() {
    for(int i = 1; i <= 5 * 3; i++) {
        cout << i << ' ' << seg[i] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    while(M--) {
        pii input; cin >> input.first >> input.second;
        arr.push_back(input);
    }

    sort(arr.begin(), arr.end());
    ll ans = 0;
    for(pii e : arr) {
        ans += query(1, 1, N, e.second + 1, N);
        update(1, 1, N, e.second);
    }

    cout << ans;
}