#include <iostream>

using namespace std;

int dp[1001][1001];
string str[1001][1001];

int main() {
    string s1, s2; cin >> s1 >> s2;
    s1 = ' ' + s1;
    s2 = ' ' + s2;
    string ans = "";
    for(int i = 1; i < s1.size(); i++) {
        for(int j = 1; j < s2.size(); j++) {
            if(s1[i] == s2[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                str[i][j] = str[i-1][j-1] + s1[i];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                str[i][j] = str[i-1][j].size() > str[i][j-1].size() ? str[i-1][j] : str[i][j-1];
            }
        }
    }

    
    cout << dp[s1.size()-1][s2.size()-1] << '\n';
    cout << str[s1.size()-1][s2.size()-1] << '\n';
}