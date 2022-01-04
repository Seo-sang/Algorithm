#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MN = 300001;
pair<int,int> arr[MN];
int a[MN];
int dp[MN];

int main() {
    int N, S; cin >> N >> S;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr + 1, arr + N + 1);
    for(int i = 1; i <= N; i++) a[i] = arr[i].first;
    dp[1] = arr[1].second;
    for(int i = 2; i <= N; i++) {
        if(a[i] - S >= a[i-1]) {
            dp[i] = dp[i-1] + arr[i].second;
        }
        else {
            auto it = upper_bound(a + 1, a + i + 1, a[i] - S);
            it--;
            int idx = it - a;
            dp[i] = max(dp[i-1], dp[idx] + arr[i].second);
        }
    }
    cout << dp[N];
}