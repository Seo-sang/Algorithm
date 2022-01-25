#include <bits/stdc++.h>

using namespace std;
const int MN = 1e8 + 1;
int arr[MN];

int main() {
    int x, y, a0, a1, N; cin >> x >> y >> arr[0] >> arr[1] >> N;
    for(int i = 2; i <= N; i++) {
        arr[i] = arr[i - 1] * x + arr[i-2] * y;
        arr[i] %= 100;
    }

    cout << arr[N] % 100;
}