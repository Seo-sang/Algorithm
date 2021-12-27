#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> arr;

int main() {
    int N, M; cin >> N >> M;
    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    int ans = 2e9;
    for(int i = 0; i < N-1; i++) {
        int now = arr[i];
        auto it = lower_bound(arr.begin(), arr.end(), now + M);
        if(it != arr.end()) {
            ans = min(ans, abs(*it - now));
        }
    }
    cout << ans;
}