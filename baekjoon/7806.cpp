#include <iostream>
#include <cmath>

using namespace std;


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    long long N, K;
    while(cin >> N >> K) {
        long long ans = 1;
        long long cpK = K;
        for(int i = 2; i * i <= cpK; i++) {
            long long cntK = 0, cntN = 0;
            while(K % i == 0) {
                cntK++;
                K /= i;
            }
            //if(cntK > 0) 
        //    cout << i << endl;
            for(long long j = i; j <= N; j *= i) {
                cntN += N / j;
            }
            ans *= pow(i, min(cntK, cntN));
        }
        if(K <= N) ans *= K;
        //cout << K << endl;
        cout << ans << '\n';
    }

    return 0;
}