#include <bits/stdc++.h>

using namespace std;
const int MN = 7;
int N, W, T, K;
int ans;
void dfs(int now, int pos, vector<int> arr) {
    vector<int> nxt;
    for(int i = 0; i < N; i++) {
        if(now != 1 && i == pos) {
            nxt.push_back(arr[i]);
            continue;
        }
        int cnt = 0;
        if(i - 1 >= 0 && arr[i-1] > 0)
            cnt++;
        if(i + 1 < N && arr[i+1] > 0)
            cnt++;
        if(cnt == 0)
            nxt.push_back(arr[i] - 3);
        else if(cnt == 1)
            nxt.push_back(arr[i] - 2);
        else if(cnt == 2)
            nxt.push_back(arr[i] - 1);
    }

    if(now == T) {
        int cnt = 0;
        for(int e : nxt)
            if(e > 0) cnt++;
        if(cnt >= K) ans++;
        return;
    }

    if(pos - 1 >= 0) {
        dfs(now + 1, pos - 1, nxt);
    }
    dfs(now + 1, pos, nxt);
    if(pos + 1 < N) {
        dfs(now + 1, pos + 1, nxt);
    }
}

int main() {
    cin >> N >> W >> T >> K;
    vector<int> arr;
    for(int i= 0; i < N; i++) {
        int a; cin >> a;
        arr.push_back(a);
    }
    dfs(1, W, arr);

    cout << ans;
}