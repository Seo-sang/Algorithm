#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

char um[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
vector<int> now;

void next(int N) {
    now[0]++;
    for(int i = 0; i < now.size(); i++) {
        if(now[i] == N) {
            now[i] -= N;
            if(i == now.size() - 1)
                now.push_back(1);
            else
                now[i + 1]++;
        }
        else
            break;
    }
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    p--;
    int turn = 1;
    
    now.push_back(0);
    
    if(p == 0)
        answer = "0";
    
    while(true) {
        next(n);
        for(int i = now.size() - 1; i >= 0; i--) {
            if(turn == p) answer += um[now[i]];
            turn = (turn + 1) % m;
            if(answer.size() == t) break;
        }
        if(answer.size() == t) break;
    }
    
    return answer;
}