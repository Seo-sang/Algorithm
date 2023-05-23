#include <bits/stdc++.h>

using namespace std;

struct trie {
    struct node {
        char now;
        map<char, node*> child;
        node(char c) : now(c) {}
    };

    node head = node(' ');

    void store(string str) {
        push(str, 0, &head);
    }

    void push(string str, int n, node* now) {
        if(n == str.size()) return;

        if(now->child.find(str[n]) == now->child.end())
            now->child[str[n]] = new node(str[n]);

        push(str, n + 1, now->child[str[n]]);
    }

    int find(node* now) {
        if(now->child.size() == 0) return 1;

        int ret = 0;
        for(auto nxt : now->child) {
            ret += find(nxt.second);
        }

        return ret;
    }
};

int main() {
    int N; cin >> N;

    trie instance;

    while(N--) {
        string str; cin >> str;
        instance.store(str);
    }

    cout << instance.find(&instance.head);
}