#include <bits/stdc++.h>

using namespace std;
vector<int> arr;
vector<int> xy;

int main() {
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            xy.push_back(arr[i] + arr[j]);
        }
    }
    int ans = 0;
    sort(xy.begin(), xy.end());
    for(int i = N - 1; i >= 0; i--) {
        for(int j = 0; j < N; j++) {
            if(arr[i] - arr[j] > 0) {
                if(binary_search(xy.begin(), xy.end(), arr[i] - arr[j])) {
                    ans = max(ans, arr[i]);
                }
            }
        }
    }
    cout << ans;
}