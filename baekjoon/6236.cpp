#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
int N, M;
int f(long long mid) {
    int ret = 0;
    long long now = 0;
    for(int i = 0; i < N; i++) {
        int e = arr[i];
        if(e > mid) return M + 1;
        if(e > now) {
            now = mid;
            ret++;
        }
        else if((M - ret) == (N - i)) {
            now = mid;
            ret++;
        }
        now -= e;
    }
    
    return ret;
}

int main() {
    cin >> N >> M;
    long long lo = 10000, hi = 0;
    for(int i = 0; i < N; i++) {
        long long a; cin >> a;
        arr.push_back(a);
        hi += a;
        lo = min(lo, a);
    }
    hi++;

    for(int i = 0; i < 40; i++) {
        long long mid = (lo + hi) / 2;

        if(f(mid) > M) lo = mid;
        else hi = mid;
    }
    cout << hi;
}