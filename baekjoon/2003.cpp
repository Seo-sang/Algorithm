#include <bits/stdc++.h>

using namespace std;
const int MN = 10001;
int arr[MN];
vector<int> sum;

int main() {
    int N, M; cin >> N >> M;
    int tmp = 0;
    sum.push_back(0);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        tmp += arr[i];
        sum.push_back(tmp);
    }
    int ans = 0;
    for(int j = N; j > 0; j--) {
        if(M > sum[j]) continue;
        auto it = lower_bound(sum.begin(), sum.end(), sum[j] - M);
        if(*it == sum[j] - M) ans++;
    }

    cout << ans;
}