#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

int main() {
    int N; cin >> N;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        if(!arr.size()) arr.push_back(a);
        else {
            if(arr.back() <= a) arr.push_back(a);
            else {
                auto it = lower_bound(arr.begin(), arr.end(), a);
                *it = a;
            }
        }
    }
    cout << N - arr.size();
}