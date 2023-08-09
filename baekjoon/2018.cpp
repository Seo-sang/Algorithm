#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    int left = 0, right = 1;
    int sum = 1;
    int ans = 0;
    while(left < right) {
        if(sum == N) {
            ans++;
            left++;
            right++;
            sum -= left;
            sum += right;
        }
        else if(sum < N) {
            right++;
            sum += right;
        }
        else {
            left++;
            sum -= left;
        }
    }
    cout << ans;
}