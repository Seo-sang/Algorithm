#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

int f(int mid) {
    int rst = 0;
    for(int e : arr) {
        rst += min(e, mid);
    }

    return rst;
}

int main() {
    int N; cin >> N;
    int l, r = 0;
    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        r = max(r, a);
        arr.push_back(a);
    }
    r++;
    int M; cin >> M;
    l = 1;
    for(int i = 0; i < 40; i++) {
        int mid = (l + r) / 2;
        int rst = f(mid);
        if(rst <= M) l = mid;
        else r = mid;
    }

    cout << l;
}