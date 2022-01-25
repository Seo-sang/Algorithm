#include <bits/stdc++.h>

using namespace std;
const int MN = 1001;

int N, Q, U, V;
int arr[MN];

int divNconq(int start, int end) {
    if(start == end) return arr[start] * U;
    int mid = (start + end) / 2;
    int ret = max(divNconq(start, mid), divNconq(mid + 1, end));
    int l = -MN, r = -MN;
    int sum = 0;
    for(int i = mid; i >= start; i--) {
        sum += (U * arr[i] + V);
        l = max(l, sum);
    }
    sum = 0;
    for(int i = mid + 1; i <= end; i++) {
        sum += (U * arr[i] + V);
        r = max(r, sum);
    }

    return max(ret, l + r - V);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> Q >> U >> V;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    while(Q--) {
        int C, A, B; cin >> C >> A >> B;
        if(C == 0)
            cout << divNconq(A-1, B-1) << '\n';
        else
            arr[A-1] = B;
    }
}