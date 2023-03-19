#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#define P pair<int,int>

using namespace std;
struct node {
    int x, y, d;
    node(int x, int y, int d) : x(x), y(y), d(d) {}
};

const int MN = 101;
const int INF = 1e9;
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int dist[MN][MN];

int solution(vector<string> board) {
    int N = board.size(), M = board[0].size();
    fill(&dist[0][0], &dist[MN-1][MN], INF);
    queue<node> q;
    
    P end;
    
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[i].size(); j++) {
            if(board[i][j] == 'R') {
                q.push(node(i, j, 0));
                dist[i][j] = 0;
            }
            if(board[i][j] == 'G') end = make_pair(i, j);
        }
    }
    
    while(!q.empty()) {
        node now = q.front(); q.pop();
        for(int d = 0; d < 4; d++) {
            int x = now.x;
            int y = now.y;
            
            while(true) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                
                if(nx >= 0 && nx < N && ny >= 0 && ny < M && board[nx][ny] != 'D') 
                    x = nx, y = ny;
                else 
                    break;
            }
            if(dist[x][y] > now.d + 1) {
                dist[x][y] = now.d + 1;
                q.push(node(x, y, now.d + 1));
            }
        }
    }
    
    if(dist[end.first][end.second] == INF) return -1;
    else return dist[end.first][end.second];
    
}