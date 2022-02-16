#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<string>> rel;
vector<vector<int>> answer;
int col;

bool isunique(vector<int> &arr) {
    for(int i = 0; i < rel.size() - 1; i++) {
        for(int j = i + 1; j < rel.size(); j++) {
            vector<string> a, b;
            for(int e : arr) {
                a.push_back(rel[i][e]);
                b.push_back(rel[j][e]);
            }
            if(a == b) return false;
            a.clear(), b.clear();
        }
    }
    return true;
}

bool isminimum(vector<int> &arr)  {
    for(vector<int> &e : answer) {
        int cnt = 0;
        for(int a : arr)
            if(find(e.begin(), e.end(), a) != e.end())
                cnt++;
        
        if(cnt == e.size()) return false;
    } 
    return true;
}

void dfs(int n, int start, vector<int> &arr) {
    if(!isminimum(arr)) return;
    if(n == arr.size()) {
        if(isunique(arr)) {
            answer.push_back(arr);
        }
        //cout << "------------\n";
        return;
    }
    
    for(int i = start; i < col; i++) {
        arr.push_back(i);
        dfs(n, i + 1, arr);
        arr.pop_back();
    }
}

int solution(vector<vector<string>> relation) {
    rel = relation;
    col = relation[0].size();
    
    vector<int> arr;
    for(int i = 1; i <= col; i++) //몇 개 포함
        for(int j = 0; j < col; j++) //어디부터 시작
            dfs(i, j, arr);
    
    return answer.size();
}