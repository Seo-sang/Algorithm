#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

struct pos {
   int x, y;
};

vector<pos> card[7];
int N, answer = 1e8;

int dist(pos a, pos b, vector<vector<int>> board) {
    int ret, cnt = 0, ctrl = 0, total = 0;
    //x축 먼저 이동
    pos start = a, end = b;
    int d = 1;
    if(start.x > end.x) d = -d;
    
    while(start.x != end.x) {
        start.x += d;
        cnt++;
        if(board[start.x][start.y] != 0) {
            ctrl++;
            cnt = 0;
        }
    }
    if(end.x == 0 || end.x == 3) {
        total = ctrl;
        if(cnt != 0)
            total++;
    }
    else {
        total = ctrl + cnt;
    }
    
    cnt = 0, ctrl = 0;
    
    d = 1;
    if(start.y > end.y) d = -d;
    
    while(start.y != end.y) {
        start.y += d;
        cnt++;
        if(board[end.x][start.y] != 0) {
            ctrl++;
            cnt = 0;
        }
    }
    if(end.y == 0 || end.y == 3) {
        total += ctrl;
        if(cnt != 0)
            total++;
    }
    else {
        total += ctrl + cnt;
    }
    
    ret = total;
    
    //y축 먼저 이동
    cnt = 0, ctrl = 0, total = 0;
    start = a, end = b;
    d = 1;
    if(start.y > end.y) d = -d;
    
    while(start.y != end.y) {
        start.y += d;
        cnt++;
        if(board[start.x][start.y] != 0) {
            ctrl++;
            cnt = 0;
        }
    }
    if(end.y == 0 || end.y == 3) {
        total = ctrl;
        if(cnt != 0)
            total++;
        
    }
    else {
        total = ctrl + cnt;
    }
    
    cnt = 0, ctrl = 0;
    
    d = 1;
    if(start.x > end.x) d = -d;
    
    while(start.x != end.x) {
        start.x += d;
        cnt++;
        if(board[start.x][end.y] != 0) {
            ctrl++;
            cnt = 0;
        }
    }
    if(end.x == 0 || end.x == 3) {
        total += ctrl;
        if(cnt != 0)
            total++;
        
    }
    else {
        total += ctrl + cnt;
    }
    
    ret = min(ret, total);
    return ret;
}

void dfs(pos now, vector<vector<int>> board, vector<int> visit, int cnt, int total) {
    for(int i = 1; i <= N; i++) {
        if(visit[i]) continue;
        int d1 = dist(now, card[i][0], board);
        int d2 = dist(now, card[i][1], board);
        int d3 = dist(card[i][0], card[i][1], board);
        int d4 = dist(card[i][1], card[i][0], board);
        board[card[i][0].x][card[i][0].y] = 0;
        board[card[i][1].x][card[i][1].y] = 0;
        visit[i] = true;
        int d;
        
        if(cnt == N - 1) {
            d = min(d1 + d3, d2 + d4);
            answer = min(answer, total + d + 2);
            return;
        }
        else {
            dfs(card[i][1], board, visit, cnt + 1, total + d1 + d3 + 2);
            dfs(card[i][0], board, visit, cnt + 1, total + d2 + d4 + 2);
        }
        
        visit[i] = false;
        board[card[i][0].x][card[i][0].y] = i;
        board[card[i][1].x][card[i][1].y] = i;
    }
}

int solution(vector<vector<int> > board, int r, int c) {
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[i].size(); j++) {
            if(board[i][j] != 0) {
                card[board[i][j]].push_back({i, j});
                N = max(N, board[i][j]);
            }
        }
    }
    
    vector<int> visit(N+1);
    for(int i = 1; i <= N; i++) visit[i] = 0;
    dfs({r,c}, board, visit, 0, 0);
    
    return answer;
}