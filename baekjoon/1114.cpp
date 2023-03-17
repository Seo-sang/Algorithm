#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;

vector<int> arr;

int main() {
    int L, K, C; cin >> L >> K >> C;
    while(K--) {
        int a; cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    arr.push_back(L);

    int ans = 1e9;
    int left = 0, right = L;
    int now, cnt;
    while(left + 1 < right) {
        now = 0, cnt = 0;
        int mid = (left + right) / 2;
        int mnum = 1e9;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] - now > mid) {
                cnt++;
                if(i == 0) {
                    cnt = 1e9;
                    break;
                }
                now = arr[i-1];
                mnum = min(mnum, arr[i-1]);
            }
        }

        if(cnt > C) left = mid;
        else {
            right = mid;
            ans = mnum;
        }
    }

    cout << right << ' ' << ans;

}