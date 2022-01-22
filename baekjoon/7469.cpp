#include <bits/stdc++.h>

using namespace std;
const int MN = 100001;
int arr[MN];
int sorted[MN];
int tmp[MN];
void merge(int s1, int e1, int s2, int e2) {
    int idx1 = s1, idx2 = s2;
    int idx = s1;
    while(idx1 <= e1 && idx2 <= e2) {
        if(sorted[idx1] < sorted[idx2])
            tmp[idx++] = sorted[idx1++];
        else
            tmp[idx++] = sorted[idx2++];
    }

    while(idx1 <= e1) {
        tmp[idx++] = sorted[idx1++];
    }
    while(idx2 <= e2) {
        tmp[idx++] = sorted[idx2++];
    }
    memcpy(sorted + s1, tmp + s1, sizeof(int) * (e2 - s1 + 1));
}

void divNconq(int start, int end, int left, int right) {
    if(end < left || right < start) return;
    if(start == end) return;
    int mid = (start + end) / 2;
    divNconq(start, mid, left, right);
    divNconq(mid + 1, end, left, right);

    merge(start, mid, mid + 1, end);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N, M; cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    while(M--) {
        int i, j, k; cin >> i >> j >> k;
        memcpy(sorted, arr, sizeof(sorted));
        i--;
        j--;
        k--;
        divNconq(0, N - 1, i, j);
        for(int a = 0; a < N; a++)
            cout << sorted[a] << ' ';
        cout << endl;
        cout << sorted[i + k] << '\n';
    }
}