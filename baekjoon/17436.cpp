#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> arr;

int main() {
    int N;
    ll M, ans = 0;
    cin >> N >> M;
    vector<int> arr(N);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for(int i = 1; i < (1 << N); i++) {
        int cnt = __builtin_popcount(i);
        ll now = 1;
        for(int j = 0; j < N; j++) if(i & (1 << j)) now *= arr[j];
        if(cnt % 2) ans += (M / now);
        else ans -= (M / now);
    }

    cout << ans;
}