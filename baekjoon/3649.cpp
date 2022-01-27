#include <bits/stdc++.h>

using namespace std;
const int MN = 1000001;
int arr[MN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int X;
    while(cin >> X) {
        int N; cin >> N;
        X *= 1e7;
        for(int i = 0; i < N; i++)
            cin >> arr[i];
        sort(arr, arr + N);
        int ans1 = -1, ans2 = -1;
        for(int i = 0; i < N - 1; i++) {
            auto it = lower_bound(arr + i + 1, arr + N, X - arr[i]);
            //cout << arr[i] << ' ' << *it << endl;
            if(*it == X - arr[i]) {
                if(ans1 == -1) {
                    ans1 = arr[i];
                    ans2 = *it;
                }
                else if(abs(ans1 - ans2) < abs(arr[i] - *it)) {
                    ans1 = arr[i];
                    ans2 = *it;
                }
            }
        }
        if(ans1 == -1) cout << "danger\n";
        else cout << "yes " << ans1 << ' ' << ans2 << '\n';
    }
}