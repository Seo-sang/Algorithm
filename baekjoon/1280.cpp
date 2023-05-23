#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MN = 200000;
const int MOD = 1e9 + 7;

int cnt[MN * 3];
ll sum[MN * 3];

void update(int node, int left, int right, int pos) {
    if(pos < left || right < pos) return;
    if(left == right) {
        cnt[node] = 1;
        sum[node] = pos;
        return;
    }

    int mid = (left + right) / 2;
    update(node * 2, left, mid, pos);
    update(node * 2 + 1, mid + 1, right, pos);
    ll leftCnt = cnt[node * 2], rightCnt = cnt[node * 2 + 1];
    ll leftSum = (leftCnt * pos - sum[node * 2]) % MOD, rightSum = (sum[node * 2 + 1] - (rightCnt * pos)) % MOD;
    cnt[node] = leftCnt + rightCnt;
    sum[node] = (leftSum + rightSum) % MOD;
}

int main() {
    int N; cin >> N;
    ll ans = 1;
    for(int i = 0; i < N; i++) {
        int input; cin >> input;
        update(1, 0, MN - 1, input);
        ans = (ans * sum[1]) % MOD;
        cout << ans << endl;
    }

    cout << ans;
}