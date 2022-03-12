#include <bits/stdc++.h>
#define P pair<ll,string>
#define ll long long
using namespace std;
const int mnum = 1e9;
set<ll> vst;
int main() {
    ll S, T; cin >> S >> T;
    if(S == T) {
        cout << 0;
        return 0;
    }
    if(T == 0) {
        cout << "-";
        return 0;
    }
    if(S != 0 && T == 1) {
        cout << "/";
        return 0;
    }
    vst.insert(S);
    queue<P> q;
    q.push({S, ""});

    while(!q.empty()) {
        P now = q.front(); q.pop();
        ll nxt = now.first * now.first;
        if(nxt <= mnum) {
            if(nxt == T) {
                cout << now.second + '*';
                return 0;
            }
            if(vst.find(nxt) == vst.end()) {
                vst.insert(nxt);
                q.push({nxt, now.second + '*'});
            }
        }
        nxt = now.first + now.first;
        if(nxt <= mnum) {
            if(nxt == T) {
                cout << now.second + '+';
                return 0;
            }
            if(vst.find(nxt) == vst.end()) {
                vst.insert(nxt);
                q.push({nxt, now.second + '+'});
            }
        }
        if(now.first != 0) {
            if(1 == T) {
                cout << '/';
                return 0;
            }
            if(vst.find(1) == vst.end()) {
                vst.insert(1);
                q.push({1, "/"});
            }
        }
    }

    cout << -1;
}