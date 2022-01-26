#include <bits/stdc++.h>

using namespace std;
const int MM = 100001;
int arr[MM];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int M, N, L; cin >> M >> N >> L;

    for(int i = 0; i < M; i++)
        cin >> arr[i];

    sort(arr, arr + M);
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        if(b > L) continue;
        int dist = L - b;
        auto it1 = upper_bound(arr, arr + M, a + dist);
        auto it2 = lower_bound(arr, arr + M, a - dist);
        if(it1 != it2)
            ans++;
    }

    cout << ans;
}