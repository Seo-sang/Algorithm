#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int> > v;

int main() {
    string poly; cin >> poly;
    int xlen = 0;
    int dotlen = 0;
    for(int i = 0; i < poly.size(); i++) {
        if(poly[i] == 'X') {
            if(dotlen != 0) {
                v.push_back(make_pair(0, dotlen));
                dotlen = 0;
            }
            xlen++;
        }
        else {
            if(xlen != 0) {
                if(xlen % 2) {
                    cout << -1;
                    return 0;
                }
                v.push_back(make_pair(xlen, 0));
                xlen = 0;
            }
            dotlen++;
        }
    }
    if(xlen % 2) {
        cout << -1;
        return 0;
    }
    v.push_back(make_pair(xlen, dotlen));
    string ans = "";
    for(pair<int,int> e : v) {
        if(e.first > 0) {
            while(e.first >= 4) {
                ans += "AAAA";
                e.first -= 4;
            }
            while(e.first) {
                ans += "BB";
                e.first -= 2;
            }
        }
        else
            while(e.second--)
                ans += '.';
    }
    cout << ans;
}