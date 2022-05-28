#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

map<string,set<string>> m;
set<string> users;

vector<string> solution(vector<string> logs) {
    vector<string> answer;
    for(string s : logs) {
        istringstream iss(s);
        string user, prob; iss >> user >> prob;
        m[prob].insert(user);
        users.insert(user);
    }
    for(auto it = m.begin(); it != m.end(); it++) {
        if(it->second.size() >= ((users.size() + 1) / 2)) answer.push_back(it->first);
    }
    sort(answer.begin(), answer.end());
    return answer;
}