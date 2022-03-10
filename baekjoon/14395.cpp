#include <bits/stdc++.h>
#define P pair<ll,string>
#define ll long long

using namespace std;
const int mnum = 1e9;
set<ll> vst;
int main() {
    ll S, T; cin >> S >> T;
    string ans = "//////////////////////////////////////////////////////";
    if(S == T) {
        cout << 0;
        return 0;
    }
    vst.insert(S);
    vst.insert(0);
    if(T == 0) {
        cout << "-";
        return 0;
    }
    if(S != 0 && T == 1) {
        cout << "/";
        return 0;
    }
    queue<P> q;
    q.push({S * S, "*"});
    q.push({S + S, "+"});
    if(S != 0) {
        vst.insert(1);
        q.push({1, "/"});
    }

    while(!q.empty()) {
        P now = q.front(); q.pop();
        ll nxt = now.first * now.first;
        if(nxt == T) {
            ans = min(ans, now.second + '*');
            cout << now.second + '*' << endl;
        }
        else if(nxt <= mnum && vst.find(nxt) == vst.end()) {
            vst.insert(nxt);
            q.push({nxt, now.second + '*'});
        }
        nxt = now.first + now.first;
        if(nxt == T) {
            ans = min(ans, now.second + '+');
            cout << now.second + '+' << endl;
        }
        else if(nxt <= mnum && vst.find(nxt) == vst.end()) {
            vst.insert(nxt);
            q.push({nxt, now.second + '+'});
        }
    }
    for(auto it = vst.begin(); it != vst.end(); it++)
        cout << *it << ' ';
    cout << endl;
    if(ans == "//////////////////////////////////////////////////////")
        cout << -1;
    else
        cout << ans;
}