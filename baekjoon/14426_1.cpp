#include <bits/stdc++.h>

using namespace std;

vector<string> arr;

int main() {
    int N, M; cin >> N >> M;

    while(N--) {
        string str; cin >> str;
        arr.push_back(str);
    }
    sort(arr.begin(), arr.end());

    int ans = 0;

    while(M--) {
        string str; cin >> str;
        auto it = lower_bound(arr.begin(), arr.end(), str);
        if(str == (*it).substr(0, str.size())) ans++;
    }

    cout << ans;
}