#include <bits/stdc++.h>

using namespace std;
const int MN = 1002;
int arr[MN][MN];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    for(vector<int>& v : skill) {
        if(v[0] == 1) v[5] *= -1;
            arr[v[1]][v[2]] += v[5];
            arr[v[1]][v[4] + 1] -= v[5];
            arr[v[3] + 1][v[2]] -= v[5];
            arr[v[3] + 1][v[4] + 1] += v[5];
    }
    //가로로 가면서 더하기
    int now = 0;
    for(int i = 0; i < board.size(); i++) {
        now = 0;
        for(int j = 0; j < board[i].size(); j++ ) {
            now += arr[i][j];
            arr[i][j] = now;
        }
    }
    //세로로 더하기
    for(int j = 0; j < board[0].size(); j++) {
        now = 0;
        for(int i = 0; i < board.size(); i++) {
            now += arr[i][j];
            board[i][j] += now;
            if(board[i][j] > 0) answer++;
        }
    }
    return answer;
}