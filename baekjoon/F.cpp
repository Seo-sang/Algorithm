#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, p, q, r; cin >> N >> p >> q >> r;
    int S = 0, K = 0, H = 0;
    string T; cin >> T;
    int ans = 0;
    for(int i = 0; i < T.size(); i++) {
        if(T[i] == 'S') {
            if(i + 2 < T.size()) {
                if(T[i + 1] == 'K' && T[i + 2] == 'H') {
                    ans++;
                    i = i + 2;
                    continue;
                }
            }
            if(i + 1 < T.size() && T[i + 1] == 'K') {
                if(r) {
                    ans++;
                    r--;
                    i++;
                }
            }
            else
                S++;
        }
        else if(T[i] == 'K') {
            if(i + 1 < T.size() && T[i + 1] == 'H') {
                if(p) {
                    ans++;
                    p--;
                    i++;
                }
            }
            else
                K++;
        }
        else
            H++;
    }
    bool chk = true;
    while(true) {
        chk = false;
        int SS = min(min(S, q), r);
        int KK = min(min(K, p), r);
        int HH = min(min(H, p), q);
        cout << S << ' ' << K << ' ' << H << endl;
        cout << p << ' ' << q << ' ' << r << endl;
        if(SS > 0 && SS >= KK && SS >= HH) {
            q -= SS;
            r -= SS;
            S -= SS;
            ans += SS;
            cout << "S " << SS << endl;
            chk = true;
        }
        else if(KK > 0 && KK >= SS && KK >= HH) {
            p -= KK;
            r -= KK;
            K -= KK;
            ans += KK;
            cout << "K " << KK << endl;
            chk = true;
        }
        else if(HH > 0 && HH >= SS && HH >= KK) {
            p -= HH;
            q -= HH;
            H -= HH;
            ans += HH;
            cout << "H " << HH << endl;
            chk = true;
        }
        if(!chk) break;
    }
    cout << ans;
}