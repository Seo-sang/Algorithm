#include <bits/stdc++.h>

using namespace std;
const int MN = 102;
int arr[MN];
vector<int> g[MN];
int p[MN];
bool s[2500];
bool visited[MN];

bool dfs(int n) {
    for(int nxt : g[n]) {
        if(visited[nxt]) continue;
        visited[nxt] = true;
        if(p[nxt] == -1 || dfs(p[nxt])) {
            p[nxt] = n;
            return 1;
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;

    //소수 구하기
    s[1] = true;
    for(int i = 2; i * i <= 2001; i++) {
        if(s[i]) continue;
        for(int j = 2 * i; j <= 2001; j += i) {
            s[j] = true;
        }
    }
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
        for(int j = 1; j < i; j++) {
            if(s[arr[i] + arr[j]]) continue;
            g[i].push_back(j + 50);
            g[j].push_back(i + 50);
        }
    }

    vector<int> ans;
    for(int nxt : g[1]) {
        memset(visited, 0, sizeof(visited));
        memset(p, -1, sizeof(p));
        p[nxt] = 1;
        for(int i = 2; i <= N; i++) {
            if(i == nxt) continue;
            memset(visited, 0, sizeof(visited));
            visited[1] = true;
            visited[nxt] = true;
            dfs(i);
        }
        int cnt = 1;
        for(int i = 52; i <= N + 50; i++) {
            if(p[i] != -1) {
                cnt++;
            }
        }
        if(cnt == N)
            ans.push_back(arr[nxt - 50]);
    }
    if(!ans.size()) cout << -1;
    else {
        sort(ans.begin(), ans.end());
        for(int e : ans)
            cout << e << ' ';
    }
}