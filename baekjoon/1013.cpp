#include <bits/stdc++.h>
#include <regex>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    regex r("(100+1+|01)+");
    while(T--) {
        string s; cin >> s;
        if(regex_match(s, r))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}