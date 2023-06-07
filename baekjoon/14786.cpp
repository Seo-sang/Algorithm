#include <bits/stdc++.h>

using namespace std;


int main() {
    double A, B, C, x;
    cin >> A >> B >> C;
    while(fabs(A * x + B * sin(x) - C) > 1e-9) {
        x = x - (A * x + B * sin(x) - C) / (A + B * cos(x));
    }

    cout << fixed;
    cout.precision(9);
    cout << x;
}