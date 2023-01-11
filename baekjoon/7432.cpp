#include <bits/stdc++.h>

using namespace std;

struct node {
    string str;
    map<string, node*> nxt;
    node(string str) : str(str) {}
};
node tree = node("");

void dfs(node* n, string add) {
    cout << add << n->str << '\n';
    for(auto it = n->nxt.begin(); it != n->nxt.end(); it++) {
        dfs(it->second, add + " ");
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    while(N--) {
        string str; cin >> str;
        int nowpos = 0, nxtpos;
        string nowstr, nxtstr;
        node* nowtree = &tree;
        while((nxtpos = str.find('\\', nowpos)) != string::npos) {
            nowstr = str.substr(nowpos, nxtpos - nowpos);
            if(nowtree->nxt.find(nowstr) == nowtree->nxt.end()) { //없는 경우
                nowtree->nxt[nowstr] = new node(nowstr);
            }
            //다음 서브트리로 이동
            nowtree = nowtree->nxt[nowstr];
            nowpos = nxtpos + 1;
        }
        nowstr = str.substr(nowpos);
        if(nowtree->nxt.find(nowstr) == nowtree->nxt.end()) { //없는 경우
            nowtree->nxt[nowstr] = new node(nowstr);
        }
    }
    for(auto it = tree.nxt.begin(); it != tree.nxt.end(); it++) {
        dfs(it->second, "");
    }

}