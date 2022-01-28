#include <bits/stdc++.h>

using namespace std;
const int MN = 2001;
int arr[MN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);
    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == j) continue;
            int num = arr[i] - arr[j];
            auto it = lower_bound(arr, arr + N, num);
            if(it == arr + i || it == arr + j) it++;
            if(it == arr + i || it == arr + j) it++;
            if(*it == num) {
                ans++;
                break;
            }
        }
    }
    cout << ans;
}