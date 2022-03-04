#include <bits/stdc++.h>

using namespace std;
map<string,int> cost;
map<string,int> in;

int to_minute(string time) {
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3));
    return h * 60 + m;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    for(string s : records) {
        istringstream iss(s);
        string time, car, inout;
        iss >> time >> car >> inout;
        int minute = to_minute(time);
        if(inout == "IN")
            in[car] = minute;
        else {
            cost[car] += minute - in[car];
            in.erase(car);
        }
    }
    int end = to_minute("23:59");
    for(auto &it : in) cost[it.first] += (end - it.second);
    for(auto &it : cost) {
        if(it.second > fees[0])
            answer.push_back(fees[1] + ((it.second - fees[0] + fees[2] - 1) / fees[2]) * fees[3]);
        else
            answer.push_back(fees[1]);
    }
    
    return answer;
}