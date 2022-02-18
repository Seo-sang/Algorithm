#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

int totime(string s) {
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    
    return h * 60 + m;
}

vector<string> tovector(string s) {
    vector<string> ret;
    
    for(int i = 0; i < s.size(); i++) {
        if(s[i+1] == '#') {
            ret.push_back(s.substr(i, 2));
            i++;
        }
        else
            ret.push_back(s.substr(i, 1));
    }
    
    return ret;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int running = 0;
    vector<string> music = tovector(m);
    
    for(string s : musicinfos) {
        istringstream iss(s);
        string tmp, title, pattern;
        int start, end;
        getline(iss, tmp, ',');
        start = totime(tmp);
        getline(iss, tmp, ',');
        end = totime(tmp);
        getline(iss, title, ',');
        getline(iss, pattern, ',');
        
        vector<string> pat = tovector(pattern);
        
        int l = pat.size();
        
        for(int i = 0; i < min(l, end - start + 1); i++) {
            int j;
            for(j = 0; j < music.size(); j++) {
                if(i + j > end - start) break;
                if(pat[(i + j) % l] != music[j]) break;
            }
            if(j == music.size()) {
                if(end - start + 1 > running) {
                    running = end - start + 1;
                    answer = title;
                }
            }
        }
    }
    return answer;
}