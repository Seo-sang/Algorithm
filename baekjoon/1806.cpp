#include <bits/stdc++.h>

using namespace std;
const int MN = 100001;
const int INF = 1e9;
int arr[MN];

int main() {
    int N, S; cin >> N >> S;
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    int left = 0, right = 0, sum = 0;
    int ans = INF;
    while(right <= N) {
        if(sum < S)
            sum += arr[right++];
        else
            sum -= arr[left++];
        if(sum >= S)
            ans = min(ans, right - left);
    }

    if(ans != INF) cout << ans;
    else cout << 0;
}