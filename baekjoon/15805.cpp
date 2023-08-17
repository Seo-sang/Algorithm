#include <bits/stdc++.h>

using namespace std;

const int MN = 200001;
int arr[MN], ans[MN];
int N, K = 0;
int idx = 0;
int cnt = 0;

void dfs(int now) {
    cnt++;
    while(true) {
        idx++;
        if(idx >= N) break;
        int nxt = arr[idx];
        if(ans[nxt] == -1) {
            ans[nxt] = now;
            dfs(nxt);
        }
        else break;
    }
}

int main() {
    cin >> N;
    memset(ans, -1, sizeof(ans));

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    ans[arr[0]] = 0;
    dfs(arr[0]);
    ans[arr[0]] = -1;
    cout << cnt << '\n';
    for(int i = 0; i < cnt; i++)
        cout << ans[i] << ' ';
}