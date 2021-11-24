#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

int f(int mid) {
    int ret = 0;
    for(int e : arr) {
        ret += min(e, mid);
    }

    return ret;
}

int main() {
    int N; cin >> N;
    int lo = 1, hi = 0;
    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        arr.push_back(a);
        hi = max(hi, a);
    }
    hi++;
    int M; cin >> M;

    for(int i = 0; i < 40; i++) {
        int mid = (lo + hi) / 2;

        int ret = f(mid);
        if(ret <= M) lo = mid;
        else hi = mid;
    }

    cout << lo;
}