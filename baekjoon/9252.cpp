#include <bits/stdc++.h>

using namespace std;
const int MN = 1001;
int dp[MN][MN];
string s1, s2;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> s1 >> s2;
    s1 = ' ' + s1;
    s2 = ' ' + s2;
    for(int i = 1; i < s1.size(); i++) {
        for(int j = 1; j < s2.size(); j++) {
            if(s1[i] == s2[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int x = s1.size() - 1;
    int y = s2.size() - 1;
    string ans = "";
    while(dp[x][y]) {
        if(dp[x][y] == dp[x-1][y]) x--;
        else if(dp[x][y] == dp[x][y-1]) y--;
        else {
            ans += s1[x];
            x--, y--;
        }
    }
    reverse(ans.begin(), ans.end());
    
    cout << dp[s1.size()-1][s2.size()-1] << '\n' << ans;
}