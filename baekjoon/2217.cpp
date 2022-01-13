#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;
const int MN = 100001;
int arr[MN];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int N; cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N, cmp);
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int sum = arr[i] * (i + 1);
        ans = max(ans, sum);
    }

    cout << ans;
}