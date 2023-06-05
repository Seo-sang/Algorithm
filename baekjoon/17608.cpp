#include <bits/stdc++.h>

using namespace std;

vector<int> arr, ans;

int main() {
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        arr.push_back(a);
    }

    reverse(arr.begin(), arr.end());
    ans.push_back(arr[0]);
    for(int i = 1; i < N; i++) {
        if(ans.back() < arr[i]) ans.push_back(arr[i]);
    }

    cout << ans.size();
}