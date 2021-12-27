#include <iostream>
#include <vector>
using namespace std;

const int MN = 2e9;

vector<int> arr;

long long f(int mid) {
    long long rst = 0;
    for(int e : arr) {
        if(e > mid) rst += (e - mid);
    }
    return rst;
}

int main() {
    int N, M; cin >> N >> M;
    int l = 0, r;
    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        r = max(r, a);
        arr.push_back(a);
    }

    for(int i = 0; i < 40; i++) {
        long long mid = (l + r) / 2;
        long long tmp = f(mid);
        if(M > tmp) r = mid;
        else l = mid;
    }
    cout << l;
}