#include <bits/stdc++.h>

using namespace std;

queue<int> q;

int main() {
    int N, W, L; cin >> N >> W >> L;

    int ans = W, sum = 0;
    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        while(true) {
            if(q.size() == W) {
                sum -= q.front();
                q.pop();
            }
            if(sum + a <= L) break;
            q.push(0);
            ans++;
        }
        sum += a;
        q.push(a);
        ans++;
    }


    cout << ans;
}