#include <bits/stdc++.h>

using namespace std;
const int MN = 1001;


struct Aho_Corasic {

    struct node {
        char now_char;
        map<char, node*> child;
        node* fail;
        bool terminal;

        node(char c) {
            now_char = c;
            terminal = false;
        }
    };

    node* root = new node(' ');

    void insert(string str) {
        node* now = root;
        for(char c : str) {
            if(now->child.find(c) == now->child.end()) now->child[c] = new node(c);
            now = now->child[c];
        }
        now->terminal = true;
    }

    void failure() {
        queue<node*> q;
        root->fail = root;
        q.push(root);

        while(!q.empty()) {
            node* now = q.front(); q.pop();
            for(auto it = now->child.begin(); it != now->child.end(); it++) {
                node* next = it->second;
                char next_char = next->now_char;
                if(now == root) {
                    next->fail = root;
                }
                else {
                    node* failnode = now->fail;

                    while(failnode != root && failnode->child.find(next_char) == failnode->child.end()) {
                        failnode = failnode->fail;
                    }
                    if(failnode->child.find(next_char) != failnode->child.end()) {
                        failnode = failnode->child[next_char];
                    }

                    next->fail = failnode;
                }
                if(next->fail->terminal) next->terminal = true;
                q.push(next);
            }
        }
    }

    bool query(string str) {
        node* now = root;

        for(char c : str) {
            while(now != root && now->child.find(c) == now->child.end())
                now = now->fail;
            if(now->child.find(c) != now->child.end()) now = now->child[c];
            if(now->terminal) return true;
        }

        return false;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    Aho_Corasic instance;
    int N; cin >> N;
    for(int i = 0;  i < N; i++) {
        string str; cin >> str;
        instance.insert(str);
    }
    instance.failure();

    int Q; cin >> Q;
    while(Q--) {
        string str; cin >> str;
        if(instance.query(str)) cout << "YES\n";
        else cout << "NO\n";
    }
}