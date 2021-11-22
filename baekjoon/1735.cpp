#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

long long lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int p1, p2, c1, c2; cin >> c1 >> p1 >> c2 >> p2;
    int son = c1 * p2 + c2 * p1;
    int parent = p1 * p2;
    int tmp = gcd(son, parent);
    cout << son / tmp <<' ' << parent / tmp;
}