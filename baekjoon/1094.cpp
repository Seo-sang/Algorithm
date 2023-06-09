#include <bits/stdc++.h>

using namespace std;

int main() {
    int X; cin >> X;
    int now = 1 << 6, sum = 1 << 6, ans = 1;
    while(sum > X) {
        now >>= 1;
        sum -= now;
        if(sum < X) {
            sum += now;
            ans++;
        }
    }

    cout << ans;
}