#include <bits/stdc++.h>

using namespace std;

const int MN = 200001;
int arr[MN], ans[MN];
int N, K = 0;
int idx = 0;

void dfs(int now) {
    idx++;
    int nxt = arr[idx];
    if(ans[nxt] == -1) {
        ans[nxt] = arr[now];
        dfs(idx);
    }
}

int main() {
    cin >> N;
    memset(ans, -1, sizeof(ans));

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    dfs(0);

    for(int i = 0; i < N; i++)
        cout << ans[i] << ' ';
}