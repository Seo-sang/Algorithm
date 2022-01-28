#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    double x, y, c; cin >> x >> y >> c;

    cout.precision(3);
    cout << fixed;

    double lo = 0, hi = min(x, y);
    while(lo + 0.000001 < hi) {
        double mid = (lo + hi) / 2;
        double xh = (double)sqrt(x * x - mid * mid);
        double yh = (double)sqrt(y * y - mid * mid);
        double h = (xh * yh) / (xh + yh);
        if(h < c) hi = mid;
        else lo = mid;
    }
    cout << hi;
}