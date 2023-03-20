#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;

const int MN = 1000001;
const int MM = 1001;
vector<P> arr;

bool cmp(P a, P b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    int R, C; cin >> R >> C;
    int N; cin >> N;
    int M; cin >> M;
    while(M--) {
        int a, b; cin >> a >> b;
        arr.push_back(make_pair(a, b));
    }
    sort(arr.begin(), arr.end(), cmp);

    int left = 0, right = max(R, C) + 1;
    int now, cnt;
    while(left + 1 < right) {
        int mid = (left + right) / 2;
        now = arr[0].second;
        cnt = 1;
        for(P pos : arr) {
            if(pos.first > mid) {
                cnt = 1e9;
                break;
            }
            if(now <= pos.second && pos.second <= now + mid - 1) continue;
            cnt++;
            now = pos.second;
        }

        if(cnt > N) left = mid;
        else right = mid;
    }

    cout << right;
}