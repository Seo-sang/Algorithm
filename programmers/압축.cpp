#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
map<string,int> m;

vector<int> solution(string msg) {
    vector<int> answer;
    m.insert({"A", 1});
    m.insert({"B", 2});
    m.insert({"C", 3});
    m.insert({"D", 4});
    m.insert({"E", 5});
    m.insert({"F", 6});
    m.insert({"G", 7});
    m.insert({"H", 8});
    m.insert({"I", 9});
    m.insert({"J", 10});
    m.insert({"K", 11});
    m.insert({"L", 12});
    m.insert({"M", 13});
    m.insert({"N", 14});
    m.insert({"O", 15});
    m.insert({"P", 16});
    m.insert({"Q", 17});
    m.insert({"R", 18});
    m.insert({"S", 19});
    m.insert({"T", 20});
    m.insert({"U", 21});
    m.insert({"V", 22});
    m.insert({"W", 23});
    m.insert({"X", 24});
    m.insert({"Y", 25});
    m.insert({"Z", 26});
    int msize = m.size();
    msize++;
    int i;
    for(i = 0; i < msg.size(); i++) {
        string s;
        int j;
        for(j = 1; i + j <= msg.size(); j++) {
            s = msg.substr(i, j);
            if(m.find(s) == m.end())
                break;
        }
        answer.push_back(m[msg.substr(i, j - 1)]);
        if((i + j) != msg.size()) {
            m.insert({msg.substr(i, j), msize++});
        }
        i = i + j - 2;
    }
    
    return answer;
}