#include <bits/stdc++.h>

using namespace std;
const int MN = 10001;
int arr[MN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        memset(arr, 0, sizeof(arr));
        for(int i = 0; i < N; i++)
            cin >> arr[i];
        sort(arr, arr + N);
        int ans = 0;
        for(int i = 0; i < N - 2; i++) {
            ans = max(ans, arr[i + 2] - arr[i]);
        }
        cout << ans << '\n';
    }
}