#include <bits/stdc++.h>

using namespace std;

struct Aho_Corasic {

    struct node {
        node *child[4];
        node* fail;
        bool terminal;

        node() {
            fill(child, child + 4, nullptr);
            terminal = false;
        }
        ~node() {
            for(int i = 0; i < 4; i++) delete child[i];
        }
    };
    node *root;

    Aho_Corasic() {
        root = new node();
        root->fail = root;
    }

    ~Aho_Corasic() {
        delete root;
    }

    void insert(string str) {
        node* now = root;
        for(char c : str) {
            int idx;
            if(c == 'A') idx = 0;
            else if(c == 'C') idx = 1;
            else if(c == 'G') idx = 2;
            else idx = 3;
            if(!now->child[idx]) now->child[idx] = new node();
            now = now->child[idx];
        }
        now->terminal = true;
    }

    void failure() {
        queue<node*> q;
        q.push(root);

        while(!q.empty()) {
            node* now = q.front(); q.pop();
            for(int i = 0; i < 4; i++) {
                node* next = now->child[i];
                if(!next) continue;

                if(now == root) next->fail = root;
                else {
                    node* failnode = now->fail;

                    while(failnode != root && !failnode->child[i]) {
                        failnode = failnode->fail;
                    }
                    if(failnode->child[i]) {
                        failnode = failnode->child[i];
                    }

                    next->fail = failnode;
                }
                if(next->fail->terminal) next->terminal = true;
                //next->terminal |= next->fail->terminal;
                q.push(next);
            }
        }
    }

    int query(string str) {
        node* now = root;
        int cnt = 0;
        for(char c : str) {
            int idx;

            if(c == 'A') idx = 0;
            else if(c == 'C') idx = 1;
            else if(c == 'G') idx = 2;
            else idx = 3;

            while(now != root && !now->child[idx]) now = now->fail;
            if(now->child[idx]) now = now->child[idx];
            if(now->terminal) cnt++;
        }

        return cnt;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while(T--) {
        int N, M; cin >> N >> M;
        string dna, marker; cin >> dna >> marker;
        Aho_Corasic instance;
        instance.insert(marker);
        for(int i = 0; i <= M; i++) {
            for(int j = i + 2; j <= M; j++) {
                string tmp = marker;
                reverse(tmp.begin() + i, tmp.begin() + j);
                instance.insert(tmp);
            }
        }
        instance.failure();
        cout << instance.query(dna) << '\n';
    }
}