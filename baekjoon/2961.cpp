#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

const int MN = 11;
vector<pii> arr;

int f(int now) {
    int sour = 1, bitter = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(now & (1 << i)) {
            sour *= arr[i].first;
            bitter += arr[i].second;
        }
    }
    return abs(sour - bitter);
}

int main() {
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        arr.push_back(pii(a, b));
    }
    int ans = 1e9;
    for(int i = 1; i < (1 << N); i++) {
        ans = min(ans, f(i));
    }

    cout << ans;
}