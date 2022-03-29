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
            if(i + 1 < T.size() && T[i + 1] == 'H') {
                if(q) {
                    ans++;
                    q--;
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

    cout << ans << endl;

    int mnum = 0;
    int sum = 0;
    int SS, KK, HH;
    int pp = p, qq = q, rr = r;


    cout << ans + mnum;
}