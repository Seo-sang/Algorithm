#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<int, int> cube;
ll ans = 0, vol = 0;

void divNconq(int length, int width, int height) {
    if(length == 0 || width == 0 || height == 0) return;
    for(auto it = cube.rbegin(); it != cube.rend(); it++) {
        if(it->second == 0) continue;
        int len = it->first;
        if(len <= length && len <= width && len <= height) {
            ans++;
            it->second--;
            vol += pow((ll)len, 3);
            divNconq(length - len, len, height);
            divNconq(length, width - len, height);
            divNconq(len, len, height - len);
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int L, W, H; cin >> L >> W >> H;
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        int A, B; cin >> A >> B;
        cube[pow(2, A)] = B;
    }

    divNconq(L, W, H);
    if(vol == ((ll)L) * W * H) cout << ans;
    else cout << -1;
}