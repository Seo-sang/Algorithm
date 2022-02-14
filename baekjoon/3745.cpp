#include <bits/stdc++.h>

using namespace std;
const int MN = 100001;
vector<int> dp;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    while(cin >> N) {
        dp.clear();
        dp.push_back(-1);
        for(int i = 0; i < N; i++) {
            int a; cin >> a;
            if(dp.back() < a) dp.push_back(a);
            else {
                auto it = lower_bound(dp.begin(), dp.end(), a);
                *it = a;
            }
        }
        cout << dp.size() - 1 << '\n';
    }
}