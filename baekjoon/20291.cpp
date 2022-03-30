#include <bits/stdc++.h>

using namespace std;
map<string, int> m;
int main() {
    int N; cin >> N;
    while(N--) {
        string str; cin >> str;
        int pos = str.find('.');
        m[str.substr(pos + 1)]++;
    }
    for(auto it = m.begin(); it != m.end(); it++)
        cout << it->first << ' ' << it->second << '\n';
}