#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

long long f(int mid) {
    long long ret = 0;
    for(int e : arr) {
        ret += ((long long)e / mid);
    }

    return ret;
}

int main() {
    int K, N; cin >> K >> N;
    long long lo = 0, hi = 0;
    for(int i = 0; i < K; i++) {
        long long a; cin >> a;
        arr.push_back(a);
        hi = max(hi, a);
    }
    hi++;
    for(int i = 0; i < 40; i++) {
        long long mid = (lo + hi) / 2;
        long long ret = f(mid);

        if(ret >= N) lo = mid;
        else hi = mid;
    }

    cout << lo;
}  