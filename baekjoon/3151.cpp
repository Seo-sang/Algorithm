#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());

    long long ans = 0;
    for(int i = 0; i < N - 2; i++) {
        for(int j = i + 1; j < N - 1; j++) {
            int sum = arr[i] + arr[j];
            auto it1 = lower_bound((arr.begin() + j + 1), arr.end(), -sum);
            auto it2 = upper_bound((arr.begin() + j + 1), arr.end(), -sum);
            ans += (it2- it1);
        }
    }

    cout << ans;
}