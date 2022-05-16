#include <bits/stdc++.h>

using namespace std;
const int MN = 5001;
const int INF = 1e9;
int arr[MN];
int N, M;
int f(int n) {
    int minnum = INF, maxnum = 0;
    int ret = 0;
    for(int i = 0; i< N; i++) {
        maxnum = max(maxnum, arr[i]);
        minnum = min(minnum, arr[i]);
        if(maxnum - minnum > n) {
            ret++;
            minnum = arr[i];
            maxnum = arr[i];
        }
    }
    return ret + 1;
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    int left = -1, right = 10001;
    while(left + 1 < right) {
        int mid = (left + right) / 2;
        int ret = f(mid);
        if(ret <= M) right = mid;
        else left = mid;
    }
    cout << right;
}