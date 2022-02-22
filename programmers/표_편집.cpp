#include <string>
#include <vector>
#include <stack>
#include <set>
#include <iostream>

using namespace std;
set<int> s;
stack<int> st;
const int MN = 1000001;
bool vst[MN];

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    for(int i = 0; i < n; i++) 
        s.insert(i);
    
    auto now = s.find(k);
        
    for(string str : cmd) {
        int num;
        
        switch(str[0]) {
            case 'U':
                num = stoi(str.substr(2));
                while(num--)
                    now--;
                break;
            case 'D':
                num = stoi(str.substr(2));
                while(num--)
                    now++;
                break;
            case 'C':
                st.push(*now);
                now++;
                if(now == s.end()) {
                    now--;
                    now--;
                }
                s.erase(st.top());
                break;
            case 'Z':
                s.insert(st.top());
                st.pop();
                break;
        }
    }
    
    for(auto it = s.begin(); it != s.end(); it++)
        vst[*it] = true;
    
    for(int i = 0; i < n; i++) {
        if(vst[i])
            answer += 'O';
        else
            answer += 'X';
    }
            
    
    return answer;
}