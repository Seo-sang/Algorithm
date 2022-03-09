#include <bits/stdc++.h>

using namespace std;
const int MN = 1001;

struct node {
    char c;
    bool end;
    map<char, node *> m;
    node() : end(false) {};
    node(char s) : c(s), end(false) {};
};

void trie(int num, node *now, string &str) {
    if(num == str.size()) return;
    char s = str[num];
    if(now->m.find(s) == now->m.end())
        now->m[s] = new node(s);
    else
        if(now->m[s]->end == true) return;

    if(num == str.size() - 1)
        now->m[s]->end = true;

    trie(num + 1, now->m[s], str);
    return;
}

bool find(int num, node *now, string &str) {
    if(num == str.size()) return false;
    char c = str[num];
    if(now->m.find(c) == now->m.end())
        return false;
    else
        if(now->m[c]->end == true) return true;

    return find(num + 1, now->m[c], str);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    node *head = new node();
    for(int i = 0;  i < N; i++) {
        string str; cin >> str;
        trie(0, head, str);
    }
    int Q; cin >> Q;
    while(Q--) {
        string str; cin >> str;
        bool ret = false;
        for(int i = 0; i < str.size(); i++) {
            string tmp = str.substr(i);
            ret = find(0, head, tmp);
            if(ret)
                break;
        }
        if(ret) cout << "YES\n";
        else cout << "NO\n";
    }
}