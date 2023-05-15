#include <bits/stdc++.h>

using namespace std;

const int MN = 500001;

int rank[3][MN];
int seg[MN * 3];

int merge(int n) {
    int left = seg[n]
    if(seg[n])
}

int quick(int n, int left, int right) {
    if(left == right) return seg[n] = left;
    int mid = (left + right ) / 2;
    quick(n * 2, left, mid);
    quick(n * 2 + 1, mid + 1, right);
    merge(n, left, mid, mid + 1, right);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, a; cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> a;
        rank[0][a] = i + 1;
    }
    for(int i = 0; i < N; i++) {
        cin >> a;
        rank[1][a] = i + 1;
    }
    for(int i = 0; i < N; i++) {
        cin >> a;
        rank[2][a] = i + 1;
    }
    quick(1, 1, N, rank[0]);

    cout << seg[1].size();
}