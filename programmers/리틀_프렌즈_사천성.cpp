#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
map<char,vector<P>> alpha;

bool isDelete(char c, P pos1, P pos2, vector<string> &board) {
    int sx, sy, dx, dy, d;
    sx = pos1.first, sy = pos1.second, dx = pos2.first, dy = pos2.second;
    (sx > dx) ? (d = -1) : (d = 1);
    bool ret = true;
    while(sx != dx) {
        if(board[sx][sy] != '.' && board[sx][sy] != c) {
            ret = false;
            break;
        }
        sx += d;
    }
    
    (sy > dy) ? (d = -1) : (d = 1);
    while(sy != dy) {
        if(board[dx][sy] != '.' && board[dx][sy] != c) {
            ret = false;
            break;
        }
        sy += d;
    }
    if(ret) return true;
    
    ret = true;
    sx = pos1.first, sy = pos1.second, dx = pos2.first, dy = pos2.second;
    (sy > dy) ? (d = -1) : (d = 1);
    while(sy != dy) {
        if(board[sx][sy] != '.' && board[sx][sy] != c) {
            ret = false;
            break;
        }
        sy += d;
    }
    
    (sx > dx) ? (d = -1) : (d = 1);
    while(sx != dx) {
        if(board[sx][dy] != '.' && board[sx][dy] != c) {
            ret = false;
            break;
        }
        sx += d;
    }
    
    return ret;
}

string solution(int m, int n, vector<string> board) {
    string answer = "";
    alpha.clear();
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == '.' || board[i][j] == '*') continue;
            char c = board[i][j];
            alpha[c].push_back(make_pair(i, j));
        }
    }
    
    while(!alpha.empty()) {
        char del = '0';
        for(auto it = alpha.begin(); it != alpha.end(); it++) {
            char c = it->first;
            vector<P> pos = it->second;
            P pos1 = pos[0], pos2 = pos[1];
            if(isDelete(c, pos1, pos2, board)) {
                del = c;
                answer += c;
                board[pos1.first][pos1.second] = '.';
                board[pos2.first][pos2.second] = '.';
                break;
            }
        }
        if(del == '0')
            break;
        alpha.erase(del);
    }
    if(!alpha.empty()) return "IMPOSSIBLE";
    return answer;
}