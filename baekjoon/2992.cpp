#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b) {
    string s1 = to_string(a);
    string s2 = to_string(b);
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    if(s1 == s2) return true;
    else return false;
}

int main() {
    int X; cin >> X;
    for(int i = X + 1; i <= 999999; i++) {
        if(to_string(i).size() != to_string(X).size()) break;
        if(cmp(i, X)) {
            cout << i;
            return 0;
        }
    }
    cout << 0;
}