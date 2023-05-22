#include <bits/stdc++.h>

using namespace std;
const int MN = 5;
int arr[MN][MN];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
set<string> ans;

void dfs(int i, int j, string str) {
    if(str.size() == 6) {
        ans.insert(str);
        return;
    }
    for(int d = 0; d < 4; d++) {
        int ni = i + dx[d];
        int nj = j + dy[d];
        if(ni >= 0 && ni < MN && nj >= 0 && nj < MN) {
            dfs(ni, nj, str + to_string(arr[ni][nj]));
        }
    }
}

int main() {
    for(int i = 0; i < MN; i++)
        for(int j = 0; j < MN; j++)
            cin >> arr[i][j];

    for(int i = 0; i < MN; i++) {
        for(int j = 0; j < MN; j++) {
            dfs(i, j, to_string(arr[i][j]));
        }
    }

    cout << ans.size();
}