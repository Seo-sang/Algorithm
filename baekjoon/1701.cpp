#include <bits/stdc++.h>

using namespace std;
int ans = 0;

void makeTable(string pattern) {
    vector<int> table(pattern.size());
    int j = 0;
    for(int i = 1; i < pattern.size(); i++) {
        while(j > 0 && pattern[i] != pattern[j])
            j = table[j-1];
        if(pattern[i] == pattern[j]) {
            table[i] = ++j;
            ans = max(ans, j);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string str; cin >> str;
    for(int i = 0; i < str.size() - 1; i++)
        makeTable(str.substr(i));

    cout << ans;
}