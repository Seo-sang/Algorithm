#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

int f(int mid) {
    int ret = 0;
    for(int e : arr) {
        ret += e / mid;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int M, N; cin >> M >> N;
    int left = 0, right = 1e9;
    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        arr.push_back(a);
        right = max(right, a);
    }

    while(left + 1 < right) {
        int mid = (left + right) / 2;
        int ret = f(mid);
        if(ret >= M) left = mid;
        else right = mid;
    }

    cout << left;
}