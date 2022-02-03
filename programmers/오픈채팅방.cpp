#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

map<string,string> m;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    //1은 들어온거, 2는 나간거
    vector<pair<int, string>> ans;
    
    for(string s : record) {
        istringstream iss(s);
        string behave, id, who;
        iss >> behave >> id >> who;
        if(behave == "Enter") {
            m[id] = who;
            ans.push_back(make_pair(1, id));
        }
        else if(behave == "Leave") {
            ans.push_back(make_pair(2, id));
        }
        else {
            m[id] = who;
        }
    }
    
    for(pair<int, string> e : ans) {
        ostringstream oss;
        if(e.first == 1)
            oss << m[e.second] << "님이 들어왔습니다.";
        else
            oss << m[e.second] << "님이 나갔습니다.";
        answer.push_back(oss.str());
    }
    
    return answer;
}