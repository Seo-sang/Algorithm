#include <bits/stdc++.h>

using namespace std;
const int MN = 1001;
vector<string> str(MN, "");
int R, C;

bool f(int mid) {
    set<string> s;
    for(int i = 0; i <C; i++) {
        string tmp = str[i].substr(mid);
        if(s.find(tmp) != s.end()) return false;
        s.insert(tmp);
    }

    return true;
}

int main() {
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        string s; cin >> s;
        for(int j = 0; j < C; j++) {
            str[j].push_back(s[j]);
        }
    }

    int left = 0, right = R + 1;
    while(left + 1 < right) {
        int mid = (left + right ) / 2;
        if(f(mid)) left = mid;
        else right = mid;
    }

    cout << left;
}