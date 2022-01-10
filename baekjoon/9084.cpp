#include <iostream>
#include <cstring>
using namespace std;

const int MN = 21;
const int MM = 10001;
int coin[MN];
int dp[MM];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        memset(coin, 0, sizeof(coin));
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= N; i++)
            cin >> coin[i];
        int M; cin >> M;
        
        for(int i = 1; i <= N; i++) {
            for(int j = coin[i]; j <= M; j++) {
                if(j == coin[i])
                    dp[j]++;
                else
                    dp[j] += dp[j-coin[i]];
            }
        }
        cout << dp[M] << '\n';
    }
}