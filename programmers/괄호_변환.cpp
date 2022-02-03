#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

bool isCorrect(string s) {
    stack<char> st;
    
    for(char c : s) {
        if(c == '(') st.push(c);
        else {
            if(st.empty()) return false;
            else st.pop();
        }
    }
    
    if(st.empty()) return true;
    else return false;
}

string dfs(string s) {
    if(s.size() == 0 || isCorrect(s)) return s;
    string u = "", v;
    int open = 0, close = 0;
    for(int i = 0; i < s.size(); i++) {
        char c = s[i];
        if(c == '(') open++;
        else close++;
        u = u + c;
        if(open == close) {
            v = s.substr(i + 1);
            break;
        }
    }
    
    if(isCorrect(u)) {
        return u + dfs(v);
    }
    else {
        string ret = '(' + dfs(v) + ')';
        u = u.substr(1, u.size() - 2);
        for(int j = 0; j < u.size(); j++) {
            if(u[j] == '(') u[j] = ')';
            else u[j] = '(';
        }
        return ret + u;
    }
}

string solution(string p) {
    string answer = "";
    
    return dfs(p);
}