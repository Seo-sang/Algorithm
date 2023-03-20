#include <bits/stdc++.h>

using namespace std;


map<string, set<string> > folder;
map<string, map<string, int> > file;
map<string, int> totalfile;

map<string,int> dfs(string now) {

    for(auto it = folder[now].begin(); it != folder[now].end(); it++) {
        map<string,int> tmp = dfs(*it);
        for(auto it2 = tmp.begin(); it2 != tmp.end(); it2++) {
            file[now][it2->first] += it2->second;
            totalfile[now] += it2->second;
        }
    }

    return file[now];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M, Q; cin >> N >> M;
    for(int i = 0; i < N + M; i++) {
        string P, F;
        int C; 
        cin >> P >> F >> C;
        if(C == 1) {
            folder[P].insert(F);
        }
        else {
            file[P][F]++;
            totalfile[P]++;
        }
    }
    dfs("main");

    cin >> Q;
    while(Q--) {
        string str; cin >> str;
        int pos = 0;
        while(true) {
            if(str.find("/") == string::npos) break;
            str = str.substr(str.find("/") + 1);
        }
        cout << file[str].size() << ' ' << totalfile[str] << '\n';
    }
}