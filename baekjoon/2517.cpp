#include <bits/stdc++.h>

using namespace std;
const int MN = 500001;
int arr[MN];
int rnk[MN];
int sorted[MN];

bool cmp(int a, int b) {
    return a > b;
}

void merge(int s1, int e1, int s2, int e2) {
    for(int i = s2; i <= e2; i++) {
        int num = arr[i];
        auto it = lower_bound(sorted + s1, sorted + e1 + 1, num, cmp);
        int idx = it - (sorted + s1);
        rnk[i] += idx;
    }
    sort(sorted + s1, sorted + e2 + 1, cmp);
}

void divNconq(int start, int end) {
    if(start == end) return;
    int mid = (start + end) / 2;

    divNconq(start, mid);
    divNconq(mid + 1, end);

    merge(start, mid, mid + 1, end);
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        sorted[i] = arr[i];
    }

    divNconq(0, N-1);

    for(int i = 0; i < N; i++)
        cout << rnk[i] + 1 << '\n';
}