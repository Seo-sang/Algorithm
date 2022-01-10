#include <iostream>
#include <algorithm>

using namespace std;

const int MN = 5001;
int dp[MN][MN];

int main() {
    int N; cin >> N;
    string s1; cin >> s1;
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    s1 = ' ' + s1;
    s2 = ' ' + s2;
    int ans = 0;
    for(int i = 1; i < s1.size(); i++) {
        for(int j = 1; j < s2.size(); j++) {
            if(s1[i] == s2[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << N - ans;
}