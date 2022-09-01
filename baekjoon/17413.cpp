#include <bits/stdc++.h>

using namespace std;

int main() {
    string str; getline(cin, str);
    bool open = false;
    string rvs = "";
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '<') {
            cout << rvs;
            rvs = "";
            open = true;
        }
        if(open) cout << str[i];
        else {
            if(str[i] == ' ') {
                cout << rvs << ' ';
                rvs = "";
            }
            else {
                rvs = str[i] + rvs;
            }
        }
        if(str[i] == '>') open = false;
    }
    cout << rvs;
}