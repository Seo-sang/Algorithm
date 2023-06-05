#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
deque<pii> dq;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, L; cin >> N >> L;

    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        if(!dq.empty()) {
            while(!dq.empty() && dq.front().first < i - L + 1) dq.pop_front();
            while(!dq.empty() && (dq.back().first < i - L + 1 || dq.back().second >= a))
                dq.pop_back();
        }
        dq.push_back(pii(i, a));
        cout << dq.front().second << ' ';
    }
}