#include <bits/stdc++.h>

using namespace std;
set<int> ans;

bool isSame(string a, string b) {
    if(a.size() != b.size()) return false;
    for(int i = 0; i < a.size(); i++)
        if(a[i] != '*' && a[i] != b[i]) return false;
    return true;
}

void dfs(int n, int num, vector<string> &user_id, vector<string> &banned_id) {
    if(n == banned_id.size())
        ans.insert(num);
    else {
        for(int i = 0; i < user_id.size(); i++) {
            if(num & (1 << i)) continue;
            if(isSame(banned_id[n], user_id[i]))
                dfs(n + 1, num | (1 << i), user_id, banned_id);
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    dfs(0, 0, user_id, banned_id);
    return ans.size();
}