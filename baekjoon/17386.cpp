#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct pos {
    ll x, y;
};

int CCW(pos A, pos B, pos C) {
    ll ret = (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
    if(ret > 0) return 1;
    else return -1;
}

int main() {
    pos A, B, C, D;
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;
    cin >> D.x >> D.y;

    int ABC = CCW(A, B, C);
    int ABD = CCW(A, B, D);
    int CDA = CCW(C, D, A);
    int CDB = CCW(C, D, B);

    if(ABC * ABD < 0 && CDA * CDB < 0) cout << 1;
    else cout << 0;

}