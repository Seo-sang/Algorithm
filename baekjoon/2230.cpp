#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

int main() {
    int N, M; cin >> N >> M;
    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        arr.push_back(a);
    }
    int ans = 2 * 1e9;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < N; i++) {
        long long now = arr[i] + M;
        if(now > arr.back()) break;
        auto it = lower_bound(arr.begin(), arr.end(), now);
        if(*it - arr[i] >= M) {
            ans = min(ans, *it - arr[i]);
        }
    }
    cout << ans;
}