#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool isNum(char now) {
    return (now >= '0' && now <= '9');
}

string solution(string new_id) {
    string answer = new_id;
    string tmp = "";
    
    for(int i = 0; i < answer.size(); i++)
        answer[i] = tolower(answer[i]);
    
    for(int i = 0; i < answer.size(); i++) {
        if(!isalpha(answer[i]) && !isNum(answer[i]) && answer[i] != '-' && answer[i] != '_' && answer[i] != '.') continue;
        tmp += answer[i];
    }
    answer = tmp;
    tmp = "";
    
    bool chk = true;
    while(chk) {
        chk = false;
        int i;
        for(i = 0; i < answer.size() - 1; i++) {
            if(answer[i] == '.' && answer[i+1] == '.') {
                i++;
                chk = true;
            }
            tmp += answer[i];
        }
        if(i < answer.size())
            tmp += answer[answer.size()-1];
        answer = tmp;
        tmp = "";
    }
    
    
    if(answer[0] == '.')
        answer = answer.substr(1);
    
    
    if(answer[answer.size()-1] == '.')
        answer = answer.substr(0, answer.size()-1);
    
    
    if(answer == "")
        answer = "a";
    
    if(answer.size() > 15)
        answer = answer.substr(0, 15);
    
    while(true) {
        if(answer[answer.size()-1] == '.')
            answer = answer.substr(0, answer.size()-1);
        else
            break;
    }
    
    while(answer.size() < 3)
        answer += answer[answer.size() - 1];
    
    
    
    return answer;
}