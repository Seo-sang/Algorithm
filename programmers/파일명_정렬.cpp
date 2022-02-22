#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct edge {
    string head;
    int number;
    string tail;
    int idx;
};
vector<edge> arr;

bool cmp(edge a, edge b) {
    if(a.head == b.head)
        return a.number < b.number;
    else
        return a.head < b.head;
}

string modify(string s) {
    string ret = "";

    for(char c : s)
        ret += toupper(c);
    
    return ret;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    for(int i = 0; i < files.size(); i++) {
        string s = modify(files[i]);
        cout << s << endl;
        edge e;
        e.head = "";
        int j;
        for(j = 0; j < s.size(); j++) {
            if(isdigit(s[j])) break;
            e.head += s[j];
        }
        string tmp = "";
        for(int k = 0; k < 5 && j < s.size(); k++, j++)
            if(isdigit(s[j]))
                tmp += s[j];
        
        e.number = stoi(tmp);
        if(j < s.size())
            e.tail = s.substr(j);
        else
            e.tail = "";
        
        e.idx = i;
        arr.push_back(e);
    }
    
    stable_sort(arr.begin(), arr.end(), cmp);
    
    //cout << arr.size();
    for(edge e : arr) {
        answer.push_back(files[e.idx]);
        //cout << e.idx << endl;
    }
    
    return answer;
}