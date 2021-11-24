#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> arr;

int main() {
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        arr.push_back(a);
    }
    int i;
    sort(arr.begin(), arr.end());
    int mnum = 2 * 1e9 + 1;
    int ans1, ans2;
    for(i = 0; i < N - 1; i++) {
        if(arr[i] >= 0) break;
        int now = arr[i];
        auto it = lower_bound(arr.begin(), arr.end(), -now);
        if(it != arr.end()) {
            if(abs(*it + now) < mnum) {
                mnum = abs(*it + now);
                ans1 = now, ans2 = *it;
            }
        }
        it--;
        if(it - arr.begin() != i) {
            if(abs(*it + now) < mnum) {
                mnum = abs(*it + now);
                ans1 = now, ans2 = *it;
            }
        }
    }
    if(i + 1 < N) {
        if(arr[i] + arr[i+1] < mnum) {
            ans1 = arr[i];
            ans2 = arr[i+1];
        }
    }

    cout << ans1 << ' ' << ans2;
}