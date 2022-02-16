#include <string>
#include <map>
#include <iostream>

using namespace std;

map<string, int> m1;
map<string, int> m2;
map<string, int> vst;

string modify(string s) {
    string ret = "";
    for(char c : s) {
        if(isalpha(c)) {
            c = tolower(c);
            ret += c;
        }
    }
    
    return ret;
}

int solution(string str1, string str2) {
    int answer = 0;
    int sum = 0;
    for(int i = 0; i < str1.size() - 1; i++) {
        if(!isalpha(str1[i]) || !isalpha(str1[i + 1])) continue;
        string s = str1.substr(i, 2);
        s[0] = tolower(s[0]);
        s[1] = tolower(s[1]);
        m1[s]++;
        vst[s]++;
    }
        
    for(int i = 0; i < str2.size() - 1; i++) {
        if(!isalpha(str2[i]) || !isalpha(str2[i + 1])) continue;
        string s = str2.substr(i, 2);
        s[0] = tolower(s[0]);
        s[1] = tolower(s[1]);
        m2[s]++;
        vst[s]++;
    }
    
    cout << str1 << ' ' << str2 << endl;
    
    for(auto it1 = m1.begin(); it1 != m1.end(); it1++) {
        for(auto it2 = m2.begin(); it2 != m2.end(); it2++) {
            if(it1->first == it2->first) {
                answer += min(it1->second, it2->second);
                sum += max(it1->second, it2->second);
                vst[it1->first] = -1;
            }
        }
    }
    
    for(auto it = vst.begin(); it != vst.end(); it++)
        if(it->second != -1)
            sum += it->second;
    
    if(sum == 0) return 65536;
    double ret = ((double)answer / sum) * 65536;
    
    return ret;
}