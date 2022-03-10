#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int a, b;
    scanf("%d:%d", &a, &b);
    int ret = gcd(a, b);
    cout << a / ret << ':' << b/ret;
}