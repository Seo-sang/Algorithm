#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MN = 101;
int board[MN][MN];
bool visit[MN][MN];
int M, N, K; 
int width;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

vector<int> widths;

void color(int y1, int x1, int y2, int x2) {
    for(int i = x1; i <= x2; i++)
        for(int j = y1; j <= y2; j++) {
            board[i][j] = 1;
        }
}

void dfs(int x, int y) {
    for(int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(nx >= 0 && nx < M && ny >= 0 && ny < N) {
            if(visit[nx][ny]) continue;
            visit[nx][ny] = true;
            if(board[nx][ny] == 0) {
                width++;
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    int ans = 0;

    cin >> M >> N >> K;
    int x1, x2, y1, y2;
    for(int i = 0; i < K; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        color(x1, y1, x2 - 1, y2 - 1);
    }
    
    
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(!visit[i][j] && !board[i][j]) {
                visit[i][j] = true;
                ans++;
                width = 1;
                dfs(i, j);
                widths.push_back(width);
            }
        }
    }
    sort(widths.begin(), widths.end());

    cout << ans << '\n';
    for(int e : widths)
        cout << e << ' ';   
}