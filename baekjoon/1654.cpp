#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

long long f(long long mid) {
    long long rst = 0;
    for(int e : arr) {
        rst += (e / mid);
    }
    return rst;
}

int main() {
    int K, N; cin >> K >> N;
    long long l, r = 0;
    for(int i = 0; i < K; i++) {
        long long a; cin >> a;
        r = max(r, a);
        arr.push_back(a);
    }
    r++;
    l = 0;
    while(l + 1 < r) {
        long long mid = (l + r) / 2;
        long long rst = f(mid);
        if(rst < N) r = mid;
        else l = mid;
    }
    cout << l;
}