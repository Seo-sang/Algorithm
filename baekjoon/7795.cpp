#include <bits/stdc++.h>

using namespace std;
vector<int> A, B;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while(T--) {
        A.clear(), B.clear();

        int N, M; cin >> N >> M;
        for(int i = 0; i < N; i++) {
            int a; cin >> a;
            A.push_back(a);
        }
        for(int i = 0; i < M; i++) {
            int a; cin >> a;
            B.push_back(a);
        }
        int ans = 0;
        sort(B.begin(), B.end());
        for(int e : A) {
            auto it = lower_bound(B.begin(), B.end(), e);
            ans += (it - B.begin());
        }
        cout << ans << '\n';
    }
}