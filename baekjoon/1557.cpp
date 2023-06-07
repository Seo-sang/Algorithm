#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MN = 50000;
int sieve[MN], chk[MN];
vector<int> arr;

ll f(ll mid) {
    ll ret = 0;
    for(int i = 1; i * i <= mid; i++) {
        ret += (mid / (i * i)) * chk[i];
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int K; cin >> K;

    //compute sieve
    for(int i = 2; i < MN; i++) {
        if(!sieve[i]) arr.push_back(i);
        for(int j = i * 2; j < MN; j += i) {
            sieve[j] = true;
        }
    }

    //check sqrt
    memset(chk, -1, sizeof(chk));
    chk[1] = 1;
    for(int i = 2; i < MN; i++) {
        for(int j = 2; j * j <= i; j++) {
            if(i % (j * j) == 0) {
                chk[i] = 0;
                break;
            }
        }
        if(!chk[i]) continue;
        int cnt = 0, now = i;
        for(int j = 0; j < arr.size(); j++) {
            if(!now) break;
            if(now % arr[j] == 0) {
                cnt++;
                now /= arr[j];
            }
        }
        if(cnt % 2) chk[i] = -1;
        else chk[i] = 1;
    }

    //binary search
    ll left = 0, right = 2 * K;
    while(left + 1 < right) {
        ll mid = (left + right) / 2;
        if(f(mid) >= K) right = mid;
        else left = mid;
    }

    cout << right;
}