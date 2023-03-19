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
    arr.push_back(0);
    sort(arr.begin(), arr.end());

    int ans = 1e9;
    int left = 0, right = L;
    int now, cnt;
    while(left + 1 < right) {
        now = L, cnt = 0;
        int mid = (left + right) / 2;
        int mnum = 1e9;
        for(int i = arr.size() - 1; i >= 0; i--) {
            if(now - arr[i] > mid) {
                if(i == arr.size() - 1) {
                    cnt = 1e9;
                    break;
                }
                cnt++;
                now = arr[i+1];
                if(now - arr[i] > mid) {
                    cnt = 1e9;
                    break;
                }
                mnum = min(mnum, arr[i+1]);
            }
        }

        if(cnt < C) {
            mnum = arr[1];
        }

        if(cnt > C) left = mid;
        else {
            right = mid;
            ans = mnum;
        }
    }

    cout << right << ' ' << ans;

}