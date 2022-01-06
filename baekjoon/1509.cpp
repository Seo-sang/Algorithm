#include <iostream>

using namespace std;

const int MN = 2501;
const int INF = 1e9;
bool dp[MN][MN];
int ans[MN];

int main() {
    string s; cin >> s;
    s = ' ' + s;
    for(int i = 1; i <= s.size() - 1; i++) dp[i][i] = true;

    for(int i = 1; i < s.size() - 1; i++)
        if(s[i] == s[i+1])
            dp[i][i+1] = true;

    for(int i = 2; i < s.size(); i++)
        for(int j = 1; j + i < s.size(); j++)
            if(s[j] == s[i + j] && dp[j+1][i + j - 1])
                dp[j][i+j] = true;

    for(int i = 1; i < s.size(); i++) {
        ans[i] = INF;
        for(int j = 1; j <= i; j++) {
            if(dp[j][i])
                ans[i] = min(ans[i], ans[j-1] + 1);
        }
    }


    cout << ans[s.size()-1];
}