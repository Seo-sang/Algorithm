#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;

const int MN = 1001;
vector<int> arr;
int p[MN];

void init(int n) {
    for(int i = 1; i <= n; i++)
        p[i] = -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, K;
    while(true) {
        cin >> N >> K;
        if(N == 0 && K == 0) break;
        init(N);
        arr.clear();
        queue<int> q;
        int now, ans = 0, idx;
        for(int i = 1; i <= N; i++) {
            int a; cin >> a;
            if(a == K) idx = i;
            if(!arr.empty()) {
                if(arr.back() + 1 != a) {
                    now = q.front(); q.pop();
                }
                p[i] = now;
            }
            else {
                p[i] = -1;
            }
            arr.push_back(a);
            q.push(i);
        }
        for(int i = 1; i <= N; i++) {
            if(i == idx) continue;
            if(p[idx] != p[i] && p[p[idx]] == p[p[i]]) ans++;
        }
        cout << ans << '\n';
    } 
}