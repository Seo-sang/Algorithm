#include <bits/stdc++.h>

using namespace std;
const int MM = 101;
vector<int> g[MM];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int M, N; cin >> M >> N;
    vector<int> arr, v;
    for(int i = 0; i < M; i++) {
        arr.clear(), v.clear();
        for(int j = 0; j < N; j++) {
            int a; cin >> a;
            arr.push_back(a);
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        v.erase((v.begin(), v.end()), v.end());
        for(int e : arr) {
            int idx = lower_bound(v.begin(), v.end(), e) - v.begin();
            g[i].push_back(idx);
        }
    }

    int ans = 0;
    for(int i = 0; i < M - 1; i++) {
        for(int j = i + 1; j < M; j++) {
            ans++;
            for(int k = 0; k < N; k++) {
                if(g[i][k] != g[j][k]) {
                    ans--;
                    break;
                }
            }
        }
    }
    cout << ans;
}