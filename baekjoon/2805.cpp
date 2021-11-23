#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

long long f(int a) {
    long long ret = 0;
    for(int e : arr) {
        ret += max(0, e - a);
    }

    return ret;
}

int main() {
    int N, M; cin >> N >> M;
    int mnum = 0;
    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        arr.push_back(a);
        mnum = max(mnum, a);
    }
    long long left = 0, right = mnum + 1;

    while(left + 1 < right) {
        int mid = (left + right) / 2;
        cout << left <<' '<<right << endl;
        long long ret = f(mid);
        if(ret >= M) left = mid;
        else right = mid;
    }
    cout << left;
}