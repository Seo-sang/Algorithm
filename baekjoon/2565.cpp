#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int,int>> arr;
vector<int> dp;
int main() {
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        arr.push_back({a, b});
    }

    sort(arr.begin(), arr.end());
    dp.push_back(-1);
    for(int i = 0; i < N; i++) {
        if(dp.back() < arr[i].second) dp.push_back(arr[i].second);
        else {
            auto it = lower_bound(dp.begin(), dp.end(), arr[i].second);
            *it = arr[i].second;
        }
    }

    cout << N - dp.size() + 1;
}