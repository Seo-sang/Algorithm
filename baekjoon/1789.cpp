#include <iostream>

using namespace std;

int main() {
    long long S; cin >> S;
    long long idx = 1;
    long long ans = 0;
    while(S >= idx) {
        ans++;
        S -= idx++;
    }
    cout << ans;
}