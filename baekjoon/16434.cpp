#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MN = 123457;
struct node {
    ll t, a, h;
    node() {}
    node(ll t, ll a, ll h) : t(t), a(a), h(h) {}
};
int N;
ll ATK; 
node arr[MN];

bool f(ll n) {
    ll hp = n;
    ll atk = ATK;
    for(int i = 0; i < N; i++) {
        if(arr[i].t == 1) {
            int mhp = arr[i].h;
            if((arr[i].h - 1) / atk > (hp -  1) / arr[i].a)
                return false;
            hp -= (arr[i].h - 1) / atk * arr[i].a;
        }
        else {
            hp = min(hp + arr[i].h, n);
            atk += arr[i].a;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> ATK;
    for(int i = 0; i < N; i++) {
        ll t, a, h; cin >> t >> a >> h;
        arr[i] = node(t, a, h);
    }
    ll left = 1, right = 1e18;
    ll rst;
    while(left <= right) {
        ll mid = (left + right)/ 2;
        bool ret = f(mid);
        if(ret) {
            rst = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }

    cout << rst;
}