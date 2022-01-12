#include <iostream>
#include <queue>

using namespace std;

const int MN = 100001;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        pq.push(a);
    }
    int ans = 0;
    if(N == 1) {
        cout << 0;
        return 0;
    }
    ans = pq.top(); pq.pop();
    ans += pq.top(); pq.pop();
    pq.push(ans);
    while(pq.size() != 1) {
        int tmp = pq.top(); pq.pop();
        tmp += pq.top(); pq.pop();
        ans += tmp;
        pq.push(tmp);
    }
    cout << ans;
}