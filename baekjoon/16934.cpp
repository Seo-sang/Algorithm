#include <bits/stdc++.h>

using namespace std;

struct node {
    map<char, node*> nxt;
    int depth;
    node(int depth) : depth(depth) {}
};
map<string, int> dup;


int find(string &str, int n, node *now) {
    if(str.size() == n) return n;
    char c = str[n];
    if(now->nxt.find(c) != now->nxt.end()) {
        return find(str, n + 1, now->nxt[c]);
    }
    else {
        now->nxt[c] = new node(now->depth + 1);
        find(str, n + 1, now->nxt[c]);
        return now->depth + 1;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    node root = node(0);
    while(N--) {
        string str; cin >> str;
        if(dup.find(str) != dup.end()) {
            cout << str << dup[str] + 1 << '\n';
        }
        else {
            int pos = find(str, 0, &root);
            cout << str.substr(0, pos) << '\n';
        }
        dup[str]++;
    }
}