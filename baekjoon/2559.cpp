#include <bits/stdc++.h>

using namespace std;

const int MN = 100001;
int arr[MN];

int main() {
    int N, K; cin >> N >> K;
    int sum = 0, left = 0, right = K;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        if(i < K) sum += arr[i];
    }
    int ans = sum;

    while(right < N) {
        sum -= arr[left++];
        sum += arr[right++];
        ans = max(ans, sum);
    }

    cout << ans;
}