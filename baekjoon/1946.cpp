#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int MN = 100001;
pair<int,int> arr[MN];

bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while(T--) {
        memset(arr, 0, sizeof(arr));
        int N; cin >> N;
        for(int i = 0; i < N; i++)
            cin >> arr[i].first >> arr[i].second;
        sort(arr, arr + N, cmp);
        int mnum = arr[0].second;
        int cnt = 0;
        for(int i = 1; i < N; i++) {
            if(arr[i].second > mnum)
                cnt++;
            mnum = min(arr[i].second, mnum);
        }

        cout << N - cnt << '\n';
    }
}