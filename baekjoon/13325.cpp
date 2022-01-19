#include <bits/stdc++.h>

using namespace std;
const int MK = 21;
int tree[2 << MK];
int K;

int dfs(int idx) {
    if(idx * 2 + 2 > pow(2, K + 1) - 1) return tree[idx];
    int left = dfs(idx * 2 + 1);
    int right = dfs(idx * 2 + 2);

    int gap = abs(left- right);
    if(left < right)
        tree[idx * 2 + 1] += gap;
    else
        tree[idx * 2 + 2] += gap;

    return max(left, right) + tree[idx];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> K;
    for(int i = 1; i <= pow(2, K + 1) - 2; i++)
        cin >> tree[i];

    dfs(0);

    int ans = 0;

    for(int i = 1; i <= pow(2, K + 1) - 1; i++)
        ans += tree[i];

    cout << ans;
}