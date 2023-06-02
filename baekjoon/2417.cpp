#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll N; cin >> N;
    ll left = -1, right = sqrt(N) + 1;
    while(left + 1 < right) {
        ll mid = (left + right) / 2;
        if(mid * mid >= N) right = mid;
        else left = mid;
    }

    cout << right;
}