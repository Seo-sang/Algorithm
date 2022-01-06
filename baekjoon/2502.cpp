#include <iostream>

using namespace std;

pair<int,int> dp[31];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int D, K; cin >> D >> K;
    dp[1].first = 1;
    dp[2].second = 1;
    for(int i = 3; i <= D; i++) {
        dp[i].first = dp[i-1].first + dp[i-2].first;
        dp[i].second = dp[i-1].second + dp[i-2].second;
    }
    int A = dp[D].first, B = dp[D].second;
    int ansA = 1, ansB = 1;
    while(A * ansA <= K) {
        int rest = K - (A * ansA);
        if(rest % B == 0) {
            ansB = rest / B;
            break;
        }
        ansA++;
    }

    cout << ansA << '\n' << ansB;
}