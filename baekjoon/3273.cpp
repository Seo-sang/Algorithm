#include <bits/stdc++.h>

using namespace std;

const int MN = 100001;
int arr[MN];

int main() {
    int N; cin >> N;

    for(int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);

    int X; cin >> X;

    int left = 0, right = N - 1;
    int ans = 0;
    while(left < right) {
        int sum = arr[left] + arr[right];
        if(sum == X) {
            ans++;
            left++;
            right--;
        }
        else if(sum > X) {
            right--;
        }
        else {
            left++;
        }
    }

    cout << ans;
}