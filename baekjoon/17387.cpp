#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct pos {
    ll x, y;
};

int CCW(pos A, pos B, pos C) {
    ll ret = (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
    if(ret > 0) return 1;
    else if(ret < 0) return -1;
    else return 0;
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

    int ret = 0;
    if(ABC == 0) {
        if(min(A.x, B.x) <= C.x && C.x <= max(A.x, B.x) && min(A.y, B.y) <= C.y && C.y <= max(A.y, B.y)) {
            ret = 1;
        }
    }
    if(ABD == 0) {
        if(min(A.x, B.x) <= D.x && D.x <= max(A.x, B.x) && min(A.y, B.y) <= D.y && D.y <= max(A.y, B.y)) {
            ret = 1;
        }
    }
    if(CDA == 0) {
        if(min(C.x, D.x) <= A.x && A.x <= max(C.x, D.x) && min(C.y, D.y) <= A.y && A.y <= max(C.y, D.y)) {
            ret = 1;
        }
    }
    if(CDB == 0) {
        if(min(C.x, D.x) <= B.x && B.x <= max(C.x, D.x) && min(C.y, D.y) <= B.y && B.y <= max(C.y, D.y)) {
            ret = 1;
        }
    }

    if(ABC * ABD < 0 && CDA * CDB < 0) ret = 1;

    cout << ret;

}