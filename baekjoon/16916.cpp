#include <bits/stdc++.h>

using namespace std;

vector<int> makeTable(string pattern) {
    vector<int> table (pattern.size(), 0);
    int j = 0;
    for(int i = 1; i < pattern.size(); i++) {
        while(j > 0 && pattern[i] != pattern[j])
            j = table[j-1];
        if(pattern[i] == pattern[j])
            table[i] = ++j;
    }

    return table;
}

bool KMP(string parent, string pattern) {
    vector<int> table = makeTable(pattern);
    int j = 0;
    for(int i = 0; i < parent.size(); i++) {
        while(j > 0 && parent[i] != pattern[j])
            j = table[j-1];
        if(parent[i] == pattern[j]) {
            if(j == pattern.size() - 1)
                return true;
            j++;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string S, P; cin >> S >> P;
    if(KMP(S, P)) cout << 1;
    else cout << 0;
}