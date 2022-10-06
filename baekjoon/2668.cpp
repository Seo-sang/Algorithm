#include <bits/stdc++.h>

using namespace std;
const int MN = 101;
int arr[MN];
bool chk[MN];
bool vst[MN];

bool dfs(int now, int start) {
    if(now == start) {
        return chk[now] = true;
    }
    if(vst[arr[now]]) return false;
    vst[arr[now]] = true;
    if(dfs(arr[now], start)) return chk[now] = true;
    else return false;
}

int main() {
    int N; cin >> N;
    int ans = 0;
    for(int i = 1; i <= N; i++) 
        cin >> arr[i];

    for(int i = 1; i <= N; i++) {
        if(chk[i]) continue;
        memset(vst, 0, sizeof(vst));
        vst[arr[i]] = true;
        dfs(arr[i], i);
    }
    for(int i = 1; i <= N; i++)
        if(chk[i]) ans++;
    cout << ans << '\n';
    for(int i = 1; i <= N; i++)
        if(chk[i])
            cout << i << '\n';
}