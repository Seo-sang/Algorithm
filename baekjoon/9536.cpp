#include <bits/stdc++.h>
using namespace std;

set<string> s;
int main() {
    int T; cin >> T;
    cin.ignore();
    while(T--) {
        s.clear();
        string sound;
        getline(cin, sound);
        while(true) {
            string str, animal, tmp, say;
            getline(cin, str);
            if(str == "what does the fox say?") break;
            istringstream iss(str);
            iss >> animal >> tmp >> say;
            s.insert(say);
        }
        string ans = "", input;
        istringstream iss2(sound);
        while(!iss2.eof()) {
            iss2 >> input;
            if(s.find(input) == s.end())
                ans = ans + " " + input;
        }
        ans = ans.substr(1);
        cout << ans << '\n';
    }
}