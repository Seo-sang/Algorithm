#include <bits/stdc++.h>

using namespace std;
int L, C;
string str = "";

bool ism(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void dfs(int n, string now, int m, int s) {
    if(now.size() == L) {
        if(m >= 1 && s >= 2) cout << now << '\n';
        return;
    }
    for(int i = n; i < C; i++) {
        if(ism(str[i]))
            dfs(i + 1, now + str[i], m + 1, s);
        else
            dfs(i + 1, now + str[i], m, s + 1);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> L >> C;
    for(int i = 0; i < C; i++) {
        char c; cin >> c;
        str.push_back(c);
    }
    sort(str.begin(), str.end());

    dfs(0, "", 0, 0);
}