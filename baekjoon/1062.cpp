#include <bits/stdc++.h>

using namespace std;

const int MN = 51;
vector<int> arr;
int ans = 0;

void dfs(int dic, int idx, int K) {
    if(K == 0) {
        int cnt = 0;
        for(int e : arr) {
            if((dic & e) == e) cnt++;
        }
        ans = max(ans, cnt);
        return;
    }
    for(int i = idx; i < 26; i++) {
        if(dic & (1 << i)) continue;
        dfs(dic | (1 << i), i + 1, K - 1);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, K; cin >> N >> K;
    while(N--) {
        string str; cin >> str;
        int input = 0;
        for(char c : str) input |= 1 << (c - 'a');
        arr.push_back(input);
    }
    if(K < 5) {
        cout << 0;
    }
    else {
        int dic = ((1 << 0) | 1 << ('n' - 'a') | 1 << ('t' - 'a') | 1 << ('i' - 'a') | 1 << ('c' - 'a'));
        dfs(dic, 0, K - 5);
        cout << ans;
    }
}