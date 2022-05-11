#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;
const int MN = 101;
const int INF = 1e9;
string board[MN];
int dp[MN][MN];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

struct node {
    int x, y, w;
};

int main() {
    int T; cin >> T;
    while(T--) {
        int h, w; cin >> h >> w;
        fill(&dp[0][0], &dp[MN-1][MN], INF);
        queue<node> q;
        for(int i = 0; i < h; i++) {
            cin >> board[i];
            for(int j = 0; j < w; j++) {
                if(board[i][j] == '$')
                    q.push({i, j, 0});
            }
        }
        while(!q.empty()) {
            
        }
    }
}