#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int MN = 500001;
const int INF = 1e9 + 7;
struct st {
    int x, y, z;
};
int seg[MN * 4];
st arr[MN];

int update(int node, int left, int right, int pos, int value) {
    if(pos < left || right < pos) return seg[node];
    if(left == right) return seg[node] = value;
    int mid = (left + right) >> 1;
    return seg[node] = min(update(node * 2, left, mid, pos, value), update(node * 2 + 1, mid + 1, right, pos, value));
}

int query(int node, int left, int right, int start, int end) {
    if(end < left || right < start) return INF;
    if(start <= left && right <= end) return seg[node];
    int mid = (left + right) >> 1;
    return min(query(node * 2, left, mid, start, end), query(node * 2 + 1, mid + 1, right, start, end));
}

bool cmp(st a, st b) {
    return a.x < b.x;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        int a; cin >> a; arr[a].x = i;
    }
    for(int i = 1; i <= N; i++) {
        int a; cin >> a; arr[a].y = i;
    }
    for(int i = 1; i <= N; i++) {
        int a; cin >> a; arr[a].z = i;
    }
    
    sort(arr + 1, arr + N + 1, cmp);
    fill(&seg[0], &seg[MN * 4], INF);
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        if(query(1, 1, N, 1, arr[i].y) > arr[i].z) ans++;
        update(1, 1, N, arr[i].y, arr[i].z);
    }

    cout << ans;
}