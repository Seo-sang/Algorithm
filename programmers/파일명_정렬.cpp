#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
    string head;
    int number;
    string tail;
    int idx;
};
vector<edge> arr;

bool cmp(edge a, edge b) {
    if(a.head == b.head) {
        if(a.number == b.number)
            return a.tail < b.tail;
        else
            return a.number < b.number;
    }
    else
        return a.head < b.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    for(int i = 0; i < files.size(); i++) {
        string s = files[i];
        edge e;
        e.head = "";
        int j;
        for(j = 0; j < s.size(); j++) {
            if(s[j] >= '0' && s[j] <= '9') break;
            e.head += s[j];
        }
        string tmp = "";
        for(; j < s.size(); j++)
            if(s[j] >= '0' && s[j] <= '9')
                tmp += s[j];
        
        e.number = stoi(tmp);
        if(j < s.size())
            e.tail = s.substr(j);
        else
            e.tail = "";
        
        arr.push_back(e);
        e.idx = j;
    }
    
    sort(arr.begin(), arr.end(), cmp);
    
    for(edge e : arr)
        answer.push_back(files[e.idx]);
    
    return answer;
}