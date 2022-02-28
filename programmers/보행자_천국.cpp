#include <bits/stdc++.h>

using namespace std;
const int MN = 501;
int MOD = 20170805;
int M, N;
int dp[MN][MN][2];
int dx[2] = {0, 1};
int dy[2] = {1, 0};

int dfs(int x, int y, int d, vector<vector<int>> &city_map) {
    if(x == M - 1 && y == N - 1) return 1;
    if(dp[x][y][d] != -1) return dp[x][y][d];
    dp[x][y][d] = 0;
    int nx = x + dx[d];
    int ny = y + dy[d];
    if(nx >= 0 && nx < M && ny >= 0 && ny < N)
        if(city_map[nx][ny] != 1)
            dp[x][y][d] += dfs(nx, ny, d, city_map);
    
    if(city_map[x][y] != 2) {
        int nd = (d + 1) % 2;
        nx = x + dx[nd];
        ny = y + dy[nd];
        if(nx >= 0 && nx < M && ny >= 0 && ny < N)
            if(city_map[nx][ny] != 1)
                dp[x][y][d] += dfs(nx, ny, nd, city_map);
    }
    
    return dp[x][y][d] %= MOD;
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    memset(dp, -1, sizeof(dp));
    M = m, N = n;
    
    return dfs(0, 0, 0, city_map);
}