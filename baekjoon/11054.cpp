#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dp;
int arr[1001];
int dp1[1001];
int dp2[1001];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N; cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    dp.push_back(-1);
    for(int i = 0; i < N; i++) {
        if(dp.back() < arr[i]) {
            dp.push_back(arr[i]);
            dp1[i] = dp.size() - 1;
        }
        else {
            auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
            *it = arr[i];
            dp1[i] = it - dp.begin();
        }
    }

    dp.clear();
    dp.push_back(-1);

    for(int i = N-1; i >= 0; i--) {
        if(dp.back() < arr[i]) {
            dp.push_back(arr[i]);
            dp2[i] = dp.size() - 1;
        }
        else {
            auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
            *it = arr[i];
            dp2[i] = it - dp.begin();
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        ans = max(ans, dp1[i] + dp2[i]);
    }

    cout << ans - 1;
}