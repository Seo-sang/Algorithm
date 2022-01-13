#include <iostream>
#include <algorithm>

using namespace std;
const int MN = 100001;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string s;
    string rvs;
    getline(cin, s);
    bool tag = false;
    for(char c : s) {
        if(c == '<') {
            if(rvs.size()) {
                reverse(rvs.begin(), rvs.end());
                cout << rvs;
                rvs.clear();
            }
            tag = true;
        }
        if(c == '>') {
            tag = false;
            cout << c;
            continue;
        }
        if(tag) {
            cout << c;
            continue;
        }
        
        if(c == ' ') {
            reverse(rvs.begin(), rvs.end());
            cout << rvs << c;
            rvs.clear();
        }
        else
            rvs.push_back(c);
    }
    if(rvs.size()) {
        reverse(rvs.begin(), rvs.end());
        cout << rvs;
        rvs.clear();
    }
}