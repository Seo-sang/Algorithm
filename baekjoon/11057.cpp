#include <iostream>

using namespace std;

int dp[10][1001];

int main() {
    int N; cin >> N;

    for(int i = 0; i < 10; i++)
        dp[i][1] = 1;

    for(int i = 1; i < N; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = j; k < 10; k++) {
                dp[k][i+1] += dp[j][i];
                dp[k][i+1] %= 10007;
            }
        }
    }

    int sum = 0;
    for(int i = 0; i < 10; i++) {
        sum += dp[i][N];
        sum %= 10007;
    }

    cout << sum;
}