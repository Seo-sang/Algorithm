#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MN = 101;
vector<int> A;
vector<int> B;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        A.push_back(a);
    }
    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        B.push_back(a);
    }
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), less<int>());
    
    int ans = 0;
    for(int i = 0; i < N; i++)
        ans += (A[i] * B[i]);

    cout << ans;
}