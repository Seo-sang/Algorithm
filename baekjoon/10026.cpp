#include <iostream>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

const int MN = 101;
string board[MN];
bool visit[MN][MN];
int normal, abnormal;
int N;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

void dfs(int x, int y, vector<char> v) {
    for(int d = 0; d < 4 ; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(nx >= 0 && nx < N && ny >= 0 && ny < N) {
            if(visit[nx][ny]) continue;
            for(char c : v) {
                if(board[nx][ny] == c) {
                    visit[nx][ny] = true;
                    dfs(nx, ny, v);
                    break;
                }
            }
        }
    }
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> board[i];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!visit[i][j]) {
                visit[i][j] = true;
                normal++;
                dfs(i, j, {board[i][j]});
            }
        }
    }
    memset(visit, 0, sizeof(visit));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!visit[i][j]) {
                visit[i][j] = true;
                abnormal++;
                if(board[i][j] == 'R' || board[i][j] == 'G')
                    dfs(i, j, {'R', 'G'});
                else
                    dfs(i, j, {'B'});
            }
        }
    }
    cout << normal << ' ' << abnormal;
}