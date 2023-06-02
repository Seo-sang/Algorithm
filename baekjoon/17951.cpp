#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

int f(int mid) {
    int ret = 0, sum = 0;
    for(int e : arr) {
        if(sum >= mid) {
            ret++;
            sum = e;
        }
        else sum += e;
    }
    if(sum >= mid) ret++;

    return ret;
}

int main() {
    int N, K; cin >> N >> K;
    int left = 0, right = 1;
    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        arr.push_back(a);
        right += a;
    }

    while(left + 1 < right) {
        int mid = (left + right) / 2;
        int ret = f(mid);
        if(ret >= K) left = mid;
        else right = mid;
    }

    cout << left;
}