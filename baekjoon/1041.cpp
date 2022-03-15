#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF = 1e9;
ll dice[6];
struct node {
    ll x, y, z;
};

node duo[12] = {
    {0, 1, 0}, {0, 2, 0}, {0, 3, 0}, {0, 4, 0}, 
    {1, 2, 0}, {2, 4, 0}, {1, 3, 0}, {3, 4, 0}, 
    {5, 1, 0}, {5, 2, 0}, {5, 3, 0}, {5, 4, 0}
};
node trio[8] = {
    {0, 1, 2}, {0, 2, 4}, {0, 1, 3}, {0, 3, 4},
    {5, 1, 2}, {5, 2, 4}, {5, 1, 3}, {5, 3, 4}
};

int main() {
    ll N; cin >> N;
    ll ans = INF;
    for(int i = 0; i < 6; i++) {
        cin >> dice[i];
        ans = min(ans, dice[i]);
    }
    if(N == 1) {
        ll mnum = 0;
        ll sum = 0;
        for(int i = 0; i < 6; i++) {
            mnum = max(mnum, dice[i]);
            sum += dice[i];
        }
        cout << sum - mnum;
        return 0;
    }
    ll vertex = 4;
    ll plat = (N - 2) * (N - 1) * 4 + (N - 2) * (N - 2);
    ll edge = 4 * (N + N - 3);
    ans *= plat;
    ll mnum = INF;
    for(int i = 0; i < 12; i++)
        mnum = min(mnum, dice[duo[i].x] + dice[duo[i].y]);
    ans += mnum * edge;
    mnum = INF;
    for(int i = 0; i < 8; i++)
        mnum = min(mnum, dice[trio[i].x] + dice[trio[i].y] + dice[trio[i].z]);
    ans += mnum * vertex;
    cout << ans;
}