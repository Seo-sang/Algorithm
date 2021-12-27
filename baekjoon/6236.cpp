#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
int N, M;
int f(int mid) {
    int rst = 1;
    int now = mid;
    for(int i = 0; i < arr.size(); i++) {
        if(M - rst == arr.size() - i) {
            return M;
        }
        int e = arr[i];
        if(now < e) {
            rst++;
            now = mid - e;
        }
        else {
            now -= e;
        }
    }
    return rst;
}

int main() {
    cin >> N >> M;
    int l =0, r;
    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        l = max(l, a);
        r += a;
        arr.push_back(a);
    }
    r++;

    for(int i = 0; i < 40; i++) {
        int mid = (l + r) / 2;
        int rst = f(mid);
        if(rst > M) l = mid;
        else r = mid;
    }
    cout << r;
}