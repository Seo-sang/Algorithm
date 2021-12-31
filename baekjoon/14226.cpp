#include <iostream>
#include <set>

using namespace std;

set<pair<int,int>> dp[2];

int main() {
    int S; cin >> S;
    int ans = 1;
    dp[0].insert({1, 0});
    bool chk = 0;
    while(true) {
        dp[ans%2].clear();
        for(pair<int,int> e : dp[(ans-1)%2]) {
            dp[ans%2].insert({e.first, e.first});
            if(e.first == S) {
                chk = 1;
                break;
            }
            if(e.second > 0) {
                dp[ans%2].insert({e.first + e.second, e.second});
                if(e.first + e.second == S) {
                    chk = 1;
                    break;
                }
            }
            dp[ans%2].insert({e.first-1, e.second});
            if(e.first - 1 == S) {
                chk = 1;
                break;
            }
        }
        if(chk) break;
        ans++;
    }
    cout << ans;
}