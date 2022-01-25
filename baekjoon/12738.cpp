#include <bits/stdc++.h>

using namespace std;
vector<int> dp;
int INF = 1e9;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    dp.push_back(-INF - 1);
    while(N--) {
        int a; cin >> a;
        if(dp.back() < a) dp.push_back(a);
        else {
            auto it = lower_bound(dp.begin(), dp.end(), a);
            *it = a;
        }
    }

    cout << dp.size() - 1;
}