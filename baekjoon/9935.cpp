#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string str, ex; cin >> str >> ex;
    string ret = "";
    for(char c : str) {
        ret.push_back(c);
        if(ret.size() >= ex.size() && ret.substr(ret.size() - ex.size()) == ex) {
            for(int i = 0; i < ex.size(); i++)
                ret.pop_back();
        }
    }
    if(ret == "") cout << "FRULA";
    else cout << ret;
}