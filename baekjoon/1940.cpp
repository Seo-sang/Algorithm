#include <bits/stdc++.h>

using namespace std;

const int MN = 15001;
int arr[MN];

int main() {
    int N, M; cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);
    int ans = 0;
    int left = 0, right = N - 1;
    while(left < right) {
        int sum = arr[left] + arr[right];
        if(sum == M) {
            ans++;
            left++;
            right--;
        }
        else if(sum < M) {
            left++;
        }
        else {
            right--;
        }
    }

    cout << ans;
}