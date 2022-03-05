#include <bits/stdc++.h>

using namespace std;
vector<int> g[18], wolfs[18], sheep;
bool vst[18];

void dfs(int n, vector<int> v, vector<int> &info) {
    if(info[n] == 0) wolfs[n] = v;
    else v.push_back(n);
    for(int nxt : g[n]) dfs(nxt, v, info);
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    for(vector<int> &e : edges) g[e[0]].push_back(e[1]);
    dfs(0, vector<int> (), info);
    
    for(int i = 1; i < info.size(); i++)
        if(info[i] == 0)
            sheep.push_back(i);
    
    do {
        int s = 1, w = 0;
        memset(vst, 0, sizeof(vst));
        for(int n : sheep) {
            int cnt = 0;
            for(int e : wolfs[n]) {
                if(vst[e]) continue;
                cnt++;
            }
            if(cnt + w < s) {
                s++;
                for(int e : wolfs[n]) {
                    if(vst[e]) continue;
                    vst[e] = true;
                    w++;
                }
            }
            else
                break;
        }
        answer = max(s, answer);
    } while(next_permutation(sheep.begin(), sheep.end()));
    
    return answer;
}