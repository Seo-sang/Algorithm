#include <bits/stdc++.h>

using namespace std;
const int MN = 1001;
map<string,int> ban;
map<string, set<string>> m;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    for(string s : report) {
        istringstream iss(s);
        string from, to;
        iss >> from >> to;
        if(m[from].find(to) == m[from].end()) {
            m[from].insert(to);
            ban[to]++;
        }
    }
    for(string s : id_list) {
        int cnt = 0;
        for(string isban : m[s]) {
            if(ban[isban] >= k)
                cnt++;
        }
        answer.push_back(cnt);
    }
    return answer;
}