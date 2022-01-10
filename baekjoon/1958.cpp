#include <iostream>
#include <cstring>

using namespace std;

const int MN = 101;
int dp[MN][MN][MN];

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    s1 = ' ' + s1;
    s2 = ' ' + s2;
    s3 = ' ' + s3;
    int ans = 0;
    for(int i = 1; i < s1. size(); i++) {
        for(int j = 1; j < s2.size(); j++) {
            for(int k = 1; k < s3.size(); k++) {
                if(s1[i] == s2[j] && s2[j] == s3[k])
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                else
                    dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
                ans = max(ans, dp[i][j][k]);
                cout << dp[i][j][k] << endl;
            }
        }
    }

    cout << ans;
}