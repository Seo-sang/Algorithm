#include <bits/stdc++.h>

using namespace std;
const int MN = 49;
int arr[MN];
int N;

void dfs(int now, vector<int>& ans) {
    if(ans.size() == 6) {
        for(int e : ans) cout << e << ' ';
        cout << '\n';
        return;
    }
    for(int i = now; i < N; i++) {
        ans.push_back(arr[i]);
        dfs(i + 1, ans);
        ans.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    while(true) {
        cin >> N;
        if(N == 0) break;
        memset(arr, 0, sizeof(arr));

        for(int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        vector<int> ans;
        dfs(0, ans);
        
        cout << '\n';
    }
}