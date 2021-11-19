#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

long long lcm(int a, int b) {
    return a*b / gcd(a, b);
}

int main() {
    int a, b; cin >> a >> b;

    cout << gcd(a, b) << '\n';
    cout << lcm(a, b);
}