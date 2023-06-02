#include <bits/stdc++.h>

using namespace std;

set<string> ans;

int main() {
    string S; cin >> S;

    for(int i = 0; i < S.size(); i++) {
        for(int j = i; j < S.size(); j++) {
            ans.insert(S.substr(i, j - i + 1));
        }
    }

    cout << ans.size();
}