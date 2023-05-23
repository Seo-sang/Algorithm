#include <bits/stdc++.h>

using namespace std;

const int MN = 100001;
int arr[MN];
int seg[MN * 3];

int init(int node, int left, int right) {

    if(left == right) return seg[node] = left;

    int mid = (left + right) / 2;
    int l = init(node * 2, left, mid);
    int r = init(node * 2 + 1, mid + 1, right);

    if(arr[l] <= arr[r]) return seg[node] = l;
    else return seg[node] = r;
}

int update(int node, int left, int right, int pos, int value) {

    if(pos < left || right < pos) return seg[node];

    if(left == right) {
        arr[pos] = value;
        return seg[node];
    }
    
    int mid = (left + right) / 2;

    int l = update(node * 2, left, mid, pos, value);
    int r = update(node * 2 + 1, mid + 1, right, pos, value);

    if(arr[l] <= arr[r]) return seg[node] = l;
    else return seg[node] = r;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int N, M; cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];

    init(1, 0, N-1);

    cin >> M;
    while(M--) {
        int mode, i, v; cin >> mode;

        if(mode == 1) {
            cin >> i >> v;
            update(1, 0, N - 1, i - 1, v);
        }
        else {
            cout << seg[1] + 1 << '\n';
        }
    }
}