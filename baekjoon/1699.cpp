#include <iostream>
#include <cmath>

using namespace std;

int dp[100001];

int m(int N) {
    if(dp[N]) return dp[N];
    if(N == 0) return 0;
    int mnum = 1e9;
    for(int i = 1; pow(i, 2) <= N; i++) {
        mnum = min(mnum, m(N - pow(i, 2)) +1);
    }
    
    return dp[N] = mnum;
}

int main() {
    int N; cin >> N;

    for(int i = 1; i * i <= N; i++)
        dp[i*i] = 1;

    cout << m(N);
}