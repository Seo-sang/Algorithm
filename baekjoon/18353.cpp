#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
vector<int> arr, dp;

int main() {
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        arr.push_back(a);
    }
    reverse(arr.begin(), arr.end());

    dp.push_back(INF);
    for(int i = 0; i < N; i++) {
        if(dp.back() < arr[i]) dp.push_back(arr[i]);
        else {
            auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
            *it = arr[i];
        }
    }
    cout << N - dp.size();

}