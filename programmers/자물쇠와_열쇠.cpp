#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;

vector<pair<int,int> > locks;
vector<pair<int,int> > keys;

void rotate() {
    vector<pair<int,int> > ret;
    
    for(pair<int,int> e : keys)
        ret.push_back(make_pair(e.second, M - 1 - e.first));
    
    keys = ret;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    M = key.size(), N = lock.size();
    
    
    for(int i = 0; i < M; i++)
        for(int j = 0; j < M; j++)
            if(key[i][j] == 1) keys.push_back(make_pair(i, j));
    
    for(int i = 0; i< N; i++)
        for(int j = 0; j < N; j++)
            if(lock[i][j] == 0) locks.push_back(make_pair(i, j));
            
    for(int r = 0; r < 4; r++) {
        rotate();
        for(int i = 1 - M; i <= N - 1; i++) {
            for(int j = 1 - M; j <= N - 1; j++) {
                int cnt = 0;
                for(pair<int,int> e : keys) {
                    int x = e.first + i;
                    int y = e.second + j;
                    if(x < 0 || x >= N || y < 0 || y >= N) continue;
                    bool chk = false;
                    auto it = find(locks.begin(), locks.end(), make_pair(x, y));
                    if(it != locks.end()) cnt++;
                    else {
                        cnt = 0;
                        break;
                    }
                }
                if(cnt == locks.size()) {
                    answer = true;
                    break;
                }
            }
        }
    }
    
    return answer;
}