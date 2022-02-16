#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <set>

using namespace std;

int to_string1(string str) {
    int h = stoi(str.substr(0, 2));
    int m = stoi(str.substr(3, 2));
    double ss = stod(str.substr(6));
    int s = ss*1000;
    
    return h * 3600000 + m * 60000 + s;
}

int to_string2(string str) {
    str = str.substr(0, str.size() - 1);
    double tmp = stod(str);
    
    return tmp * 1000 - 1;
}

int solution(vector<string> lines) {
    int answer = 0;
    string tmp, s1, s2;
    vector<pair<int,int>> arr;
    vector<int> ms;
    
    for(string s : lines) {
        istringstream iss(s);
        iss >> tmp >> s1 >> s2;
        int end = to_string1(s1);
        int start = end - to_string2(s2);
        arr.push_back({start, end});
    }
    sort(arr.begin(), arr.end());
    
    for(pair<int,int> e : arr) {
        int cnt = 1;
        e.first -= 999;
        for(int i = 0; i < ms.size(); i++)
            if(ms[i] >= e.first) cnt++;
        ms.push_back(e.second);
        answer = max(answer, cnt);
    }
    
    return answer;
}