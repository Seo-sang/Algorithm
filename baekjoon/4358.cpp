#include <bits/stdc++.h>

using namespace std;
map<string, int> m;

int main() {
    string str;
    int cnt = 0;
    while(getline(cin, str)) {
        cnt++;
        m[str]++;
    }
    cout.precision(4);
    cout << fixed;
    for(auto it = m.begin(); it != m.end(); it++)
        cout << it->first << ' ' << (double)it->second * 100 / cnt << '\n';
}