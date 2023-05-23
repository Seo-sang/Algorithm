#include <bits/stdc++.h>

using namespace std;

struct trie {
    struct node {
        bool terminal;
        map<char, node*> child;
        node() : terminal(false) {}
    };

    node* head = new node();

    void store(string str) {
        store_dfs(str, 0, head);
    }

    bool find(string str) {
        return find_dfs(str, 0, head);
    }

private:
    void store_dfs(string str, int n, node* now) {
        if(n == str.size()) {
            now->terminal = true;
            return;
        }

        if(now->child.find(str[n]) == now->child.end()) 
            now->child[str[n]] = new node();

        store_dfs(str, n + 1, now->child[str[n]]);
        now->terminal = false;
    }

    bool find_dfs(string str, int n, node* now) {
        if(str.size() == n) return true;
        if(now->terminal) return false;

        bool ret = false;
        for(auto nxt : now->child) {
            if(str[n] == nxt.first)
                ret |= find_dfs(str, n + 1, nxt.second);
        }

        return ret;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    trie instance;

    int N, M; cin >> N >> M;

    while(N--) {
        string str; cin >> str;
        instance.store(str);
    }

    int ans = 0;
    while(M--) {
        string str; cin >> str;
        if(instance.find(str)) ans++;
    }

    cout << ans;
}