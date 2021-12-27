#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

map<string, int> m;

void dfs(string s, string now, int n) {
    if(now.size() > 1) {
        sort(now.begin(), now.end());
        m[now]++;
    }
    if(s.size() == n) return;
    for(int i = n; i < s.size(); i++) {
        dfs(s, now + s[i], i+1);
    }
    return;
}

bool is(int size, vector<int> &course) {
    bool ret = false;
    for(int e : course) {
        if(e == size) {
            ret = true;
            break;
        }
    }
    
    return ret;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    int cnt[11];
    vector<string> ans[11];
    memset(cnt, 0, sizeof(cnt));
    
    for(string e : orders) {
        dfs(e, "",0);
    }
    
    for(auto it = m.begin(); it != m.end(); it++) {
        int size = it->first.size();
        if(is(size, course)) {
            if(cnt[size] < it->second && it->second > 1) {
                ans[size].clear();
                ans[size].push_back(it->first);
                cnt[size] = it->second;
            }
            else if(cnt[size] == it->second && it->second > 1)
                ans[size].push_back(it->first);
        }
    }
    
    for(int i = 1; i <= 10; i++) {
        if(ans[i].size()) {
            for(string e : ans[i]) {
                sort(e.begin(), e.end());
                answer.push_back(e);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}