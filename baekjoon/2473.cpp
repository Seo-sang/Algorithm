#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MN = 5001;
ll arr[MN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);

    ll mnum = 3e9 + 1;
    ll ans1, ans2, ans3;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N - 1; j++) {
            ll num = arr[i] + arr[j];
            auto it = lower_bound(arr + j + 1, arr + N, -num);
            if(it - arr == N) it--;
            else if(j != (it - arr - 1) && abs(num + *it) > abs(num + *(it - 1))) it--;
            if(mnum > abs(num + *it)) {
                mnum = abs(num + *it);
                ans1 = arr[i], ans2 = arr[j], ans3 = *it;
            }
        }
    }
    cout << ans1 << ' ' << ans2 << ' ' << ans3;
}