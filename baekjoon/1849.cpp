#include <bits/stdc++.h>

using namespace std;
const int MN = 100001;
int arr[MN];
int seg[MN * 3];
int N; 
int init(int n, int left, int right) {
    if(left == right) return seg[n] = 1;
    int mid = (left + right) / 2;
    return seg[n] = init(n * 2, left, mid) + init(n * 2 + 1, mid + 1, right);
}

int update(int n, int left, int right, int num, int pos) {
    if(left == right) {
        arr[left] = num;
        return seg[n] = 0;
    }

    int mid = (left + right) / 2;
    if(seg[n * 2] >= pos) return seg[n] = update(n * 2, left, mid, num, pos) + seg[n * 2 + 1];
    else return seg[n] = seg[n * 2] + update(n * 2 + 1, mid + 1, right, num, pos - seg[n * 2]);
}


int main() {
    cin >> N;
    init(1, 1, N);
    for(int i = 1 ; i <= N; i++) {
        int pos; cin >> pos;
        update(1, 1, N, i, pos + 1);
    }
    for(int i = 1; i <= N; i++)
        cout << arr[i] << '\n';
}