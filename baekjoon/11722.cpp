#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[1001];
vector<int> dp;

int main() {
    int N; cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    reverse(arr, arr + N);

    dp.push_back(-1);
    for(int i = 0; i < N; i++) {
        if(dp.back() < arr[i]) dp.push_back(arr[i]); 
        else {
            auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
            *it = arr[i];
        }
    }
    cout << dp.size() - 1;
}