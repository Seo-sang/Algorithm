#include <bits/stdc++.h>

using namespace std;

const int MN = 4;
string arr[MN];
int dp[1 << 16];
int N, M;

void dfs(int vst, int sum) {
    if(dp[vst] >= sum) return;
    dp[vst] = sum;
    int now;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            now = 1 << (M * i + j);
            int num = arr[i][j] - '0';
            if(!(vst & now)) dfs(vst | now, sum + num);
            //가로
            if(j + 1 < M) {
                now |= (1 << (M * i + j + 1));
                num = num * 10 + (arr[i][j + 1] - '0');
                if(!(vst & now)) dfs(vst | now, sum + num);
            }
            if(j + 2 < M) {
                now |= (1 << (M * i + j + 2));
                num = num * 10 + (arr[i][j + 2] - '0');
                if(!(vst & now)) dfs(vst | now, sum + num);
            }
            if(j + 3 < M) {
                now |= (1 << (M * i + j + 3));
                num = num * 10 + (arr[i][j + 3] - '0');
                if(!(vst & now)) dfs(vst | now, sum + num);
            }
            //세로
            now = 1 << (M * i + j);
            num = arr[i][j] - '0';
            if(i + 1 < N) {
                now |= (1 << (M * (i + 1) + j));
                num = num * 10 + (arr[i + 1][j] - '0');
                if(!(vst & now)) dfs(vst | now, sum + num);
            }
            if(i + 2 < N) {
                now |= (1 << (M * (i + 2) + j));
                num = num * 10 + (arr[i + 2][j] - '0');
                if(!(vst & now)) dfs(vst | now, sum + num);
            }
            if(i + 3 < N) {
                now |= (1 << (M * (i + 3) + j));
                num = num * 10 + (arr[i + 3][j] - '0');
                if(!(vst & now)) dfs(vst | now, sum + num);
            }
        }
    }
}


int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    dfs(0, 0);

    cout << dp[(1 << (N * M)) - 1];
}