#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MN = 200001;
const int MOD = 1000000007;

int cnt[MN * 3];
ll sum[MN * 3];

void update(int node, int left, int right, ll pos) {
    if(pos < left || right < pos) return;
    if(left == right) {
        cnt[node]++;
        sum[node] += pos;
        return;
    }

    int mid = (left + right) / 2;
    update(node * 2, left, mid, pos);
    update(node * 2 + 1, mid + 1, right, pos);
    cnt[node] = cnt[node * 2] + cnt[node * 2 + 1];
    sum[node] = sum[node * 2] + sum[node * 2 + 1];
}

ll query(int node, int left, int right, ll pos) {
    if(pos < left) return (sum[node] - cnt[node] * pos) % MOD;  //오른쪽에 있는 나무들
    else if(right < pos) return (cnt[node] * pos - sum[node]) % MOD;    //왼쪽에 있는 나무들
    else if(left == right) return 0;
    else {
        int mid = (left + right) / 2;
        return (query(node * 2, left, mid, pos) + query(node * 2 + 1, mid + 1, right, pos)) % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    ll ans = 1;
    ll sum = 0;

    for(int i = 0; i < N; i++) {
        ll input; cin >> input;
        update(1, 0, MN -1, input);
        ll rst = query(1, 0, MN - 1, input);
        sum = (sum + rst) % MOD;
        if(rst > 0)
            ans = (ans * rst) % MOD;
    }
    if(sum == 0) cout << 0;
    else cout << ans;
}