#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    string ex = "UCPC";
    getline(cin, s);

    int idx = 0;
    for(char c : s)
        if(ex[idx] == c) idx++;
    if(idx == 4) cout << "I love UCPC";
    else cout << "I hate UCPC";
}