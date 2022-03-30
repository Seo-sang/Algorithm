#include <bits/stdc++.h>

using namespace std;

int main() {
    string str; cin >> str;
    string ans = "";
    bool cap = false;
    if(isupper(str[0]) || str[0] == '_' || str.back() == '_') {
        cout << "Error!";
        return 0;
    }
    for(int i = 0; i < str.size(); i++) {
        if(!isalpha(str[i]) && str[i] != '_') {
            cout << "Error!";
            return 0;
        }
        if(str[i] == '_') {
            cap = true;
            if(str[i-1] == '_') {
                cout << "Error!";
                return 0;
            }
        }
        else if(isupper(str[i])) {
            if(cap) {
                cout << "Error!";
                return 0;
            }
            ans += '_';
            ans += tolower(str[i]);
        }
        else {
            if(cap)
                ans += toupper(str[i]);
            else
                ans += str[i];
            cap = false;
        }
    }
    cap = false;
    bool underscore = false;
    for(char c : ans) {
        if(isupper(c)) cap = true;
        if(c == '_') underscore = true;
    }

    if(cap && underscore)
        cout << "Error!";
    else
        cout << ans;
}