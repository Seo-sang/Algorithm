#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    string s, t, ss, tt; cin >> s >> t;
    int l = lcm(s.size(), t.size());
    ss = s, tt = t;
    while(ss.size() < l)
        ss += s;
    while(tt.size() < l)
        tt += t;
    cout << (ss == tt);
}