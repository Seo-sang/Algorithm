#include <iostream>

using namespace std;

const int MN = 10001;
double dp[MN];

int main() {
    int N; cin >> N;
    dp[0] = 1;
    double ans = 0.0;
    for(int i = 1; i <= N; i++) {
        double f; cin >> f;
        if(f < dp[i-1] * f)
            dp[i] = dp[i-1] * f;
        else
            dp[i] = f;
        ans = max(ans, dp[i]);
    }


    printf("%0.3lf", ans);
}