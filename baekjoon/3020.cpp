#include <bits/stdc++.h>

using namespace std;
const int MN = 200001;
const int MH = 500001;

vector<int> up;
vector<int> down;

int arr[MH];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, H; cin >> N >> H;

    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        if(i % 2)
            up.push_back(H - a);
        else
            down.push_back(a);
    }
    sort(up.begin(), up.end());
    sort(down.begin(), down.end());

    for(int i = 2; i < H; i++) {
        auto it = lower_bound(up.begin(), up.end(), i);
        arr[i] = it - up.begin();
    }
    arr[H] = up.size();
    int mnum = 1e9;
    int cnt = 0;
    for(int i = 1; i <= H; i++) {
        auto it = lower_bound(down.begin(), down.end(), i);
        arr[i] += (down.end() - it);
        if(arr[i] < mnum) {
            mnum = arr[i];
            cnt = 1;
        }
        else if(arr[i] == mnum) cnt++;
    }
    cout << mnum << ' ' << cnt;
}