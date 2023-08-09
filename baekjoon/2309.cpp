#include <bits/stdc++.h>

using namespace std;
const int MN = 9;
int arr[MN];
bool chk = false;

void dfs(int now, int sum, vector<int> &ans) {
    if(chk) return;
    if(ans.size() == 7 && sum == 100) {
        for(int e : ans)
            cout << e << '\n';
        chk = true;
        return;
    }

    for(int nxt = now; nxt < MN; nxt++) {
        ans.push_back(arr[nxt]);
        dfs(nxt + 1, sum + arr[nxt], ans);
        ans.pop_back();
    }
}

int main() {
    for(int i = 0; i < MN; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + MN);
    vector<int> ans;
    dfs(0, 0, ans);
}