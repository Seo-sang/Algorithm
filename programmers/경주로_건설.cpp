#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
const int MN = 26;
const int INF = 1e9;

struct edge {
    int x, y, d;
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int cost[MN][MN][4];
int N;
int solution(vector<vector<int>> board) {
    int answer = INF;
    N = board.size();
    queue<edge> q;
    fill(&cost[0][0][0], &cost[MN - 1][MN-1][4], INF);
    
    if(board[0][1] != 1)
        q.push({0, 1, 1});
    if(board[1][0] != 1)
        q.push({1, 0, 0});
    
    for(int i = 0; i < 4; i++)
        cost[0][0][i] = 0;
    
    cost[0][1][1] = 100;
    cost[1][0][0] = 100;
    
    while(!q.empty()) {
        edge now = q.front(); q.pop();
        int nx, ny, nd;
        nd = now.d;
        nx = now.x + dx[nd];
        ny = now.y + dy[nd];
        
        if(nx >= 0 && nx < N && ny >= 0 && ny < N) {
            if(board[nx][ny] != 1 && cost[nx][ny][nd] > cost[now.x][now.y][now.d] + 100) {
                cost[nx][ny][nd] = cost[now.x][now.y][now.d] + 100;
                q.push({nx,ny, nd});
            }
        }
        
        nd = (now.d + 3) % 4;
        nx = now.x + dx[nd];
        ny = now.y + dy[nd];
        
        if(nx >= 0 && nx < N && ny >= 0 && ny < N) {
            if(board[nx][ny] != 1 && cost[nx][ny][nd] > cost[now.x][now.y][now.d] + 600) {
                cost[nx][ny][nd] = cost[now.x][now.y][now.d] + 600;
                q.push({nx,ny, nd});
            }
        }
        
        nd = (now.d + 1) % 4;
        nx = now.x + dx[nd];
        ny = now.y + dy[nd];
        
        if(nx >= 0 && nx < N && ny >= 0 && ny < N) {
            if(board[nx][ny] != 1 && cost[nx][ny][nd] > cost[now.x][now.y][now.d] + 600) {
                cost[nx][ny][nd] = cost[now.x][now.y][now.d] + 600;
                q.push({nx,ny, nd});
            }
        }
    }
    for(int i = 0; i < 4; i++)
        answer = min(answer, cost[N-1][N-1][i]);
    return answer;
}