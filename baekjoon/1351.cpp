#include <bits/stdc++.h>
#define ll long long

using namespace std;

map<ll, ll> dp;

ll dfs(ll n, ll P, ll Q) {
    if(dp.find(n) != dp.end()) return dp[n];

    return dp[n] = dfs(n / P, P, Q) + dfs(n / Q, P, Q);
    
}

int main() {
    ll N, P, Q; 
    cin >> N >> P >> Q;

    dp[0] = 1;
    dp[1] = 2; 

    cout << dfs(N, P, Q);
}