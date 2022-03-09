#include <bits/stdc++.h>

using namespace std;
int alpha[27];
int main() {
    string str; cin >> str;
    string prefix = "";
    string suffix = "";
    int odd = 0;
    for(char c : str)
        alpha[c - 'A']++;
    for(char c = 'A'; c <= 'Z'; c++) {
        while(alpha[c - 'A'] > 1) {
            prefix = prefix + c;
            suffix = c + suffix;
            alpha[c - 'A'] -= 2;
        }
    }
    for(char c = 'A'; c <= 'Z'; c++)
        if(alpha[c - 'A'] % 2) odd++;
    if(odd > 1) {
        cout << "I'm Sorry Hansoo";
        return 0;
    }
    for(char c = 'A'; c <= 'Z'; c++) {
        if(alpha[c - 'A']) {
            prefix = prefix + c;
            break;
        }
    }

    cout << prefix + suffix;
}