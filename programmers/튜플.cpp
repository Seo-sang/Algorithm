#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
vector<vector<int>> arr;

bool cmp(vector<int> a, vector<int> b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> tmp;
    set<int> vst;
    string num = "";
    for(int i = 1; i < s.size() - 1; i++) {
        switch(s[i]) {
            case ',':
                if(s[i-1] != '}') {
                    tmp.push_back(stoi(num));
                    num = "";
                }
                break;
            case '{':
                break;
            case '}':
                tmp.push_back(stoi(num));
                arr.push_back(tmp);
                num = "";
                tmp.clear();
                break;
            default:
                num += s[i];
                break;
        }
    }
    
    sort(arr.begin(), arr.end(), cmp);
    
    for(vector<int> &v : arr) {
        for(int e : v) {
            if(vst.find(e) == vst.end()) {
                vst.insert(e);
                answer.push_back(e);
            }
        }
    }
    
    return answer;
}