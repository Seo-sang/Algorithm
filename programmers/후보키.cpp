#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int row, col;
int answer = 0;
int bulk = 9;

void dfs(int n, vector<int> idx, vector<vector<string>> &relation) {
    bool ret = true;
    for(int i = 0; i < relation.size() - 1; i++) {
        for(int j = i + 1; j < relation.size(); j++) {
            int cnt = 0;
            for(int e : idx) {
                if(relation[i][e] == relation[j][e]) {
                    cnt++;
                    break;
                }
            }
            //모두 같은 것이 있으면
            if(cnt == idx.size()) {
                ret = false;
                break;
            }
        }
    }
    
    //같은 것이 없는 경우
    if(ret) {
        cout <<idx[0] << ' ' << idx.size() << endl;
        if(bulk == (int)idx.size())
            answer++;
        else if(bulk > (int)idx.size()) {
            bulk = (int)idx.size();
            answer = 1;
        }
    }
    
    //더 작은게 있는 경우 더이상 탐색하지 않음
    if(bulk <= (int)idx.size()) return;
    
    for(int i = n + 1; i < col; i++) {
        idx.push_back(i);
        dfs(i, idx, relation);
        idx.pop_back();
    }
}

int solution(vector<vector<string>> relation) {
    row = relation.size();
    col = relation[0].size();
    
    for(int num = 0; num < col; num++) {
        dfs(num, {num}, relation);
    }
    
    return answer;
}