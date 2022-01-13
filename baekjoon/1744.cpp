#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
const int MN = 51;
int arr[MN];
multiset<pair<int,int>> s;
int main() {
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        s.insert({abs(a), a});
    }
    int ans = 0;
    while(!s.empty()) {
        auto now = s.end();
        now--;
        s.erase(now);
        if(s.empty()) {
            ans += now->second;
            break;
        }
        int num = now->second;
        int mnum = now->second;
        auto e = s.end();
        for(auto it = s.begin(); it != s.end(); it++) {
            if(num * (it->second) > mnum) {
                mnum = num * (it->second);
                e = it;
            }
        }
        if(e == s.end())
            ans += num;
        else {
            ans += mnum;
            s.erase(e);
        }
    }
    cout << ans;
}