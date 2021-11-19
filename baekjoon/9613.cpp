#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int T; cin >> T;
    while(T--) {
        arr.clear();
        int N; cin >> N;
        for(int i = 0; i < N; i++) {
            int a; cin >> a;
            arr.push_back(a);
        }
        long long ans = 0;
        for(int i = 0; i < N-1; i++) {
            for(int j = i+1; j < N; j++) {
                ans += gcd(arr[i], arr[j]);
            }
        }
        cout << ans << '\n';
    }
}