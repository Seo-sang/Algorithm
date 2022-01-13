#include <iostream>

using namespace std;
const int MN = 101;
const int INF = 1e9;

int main() {
    int N, M; cin >> N >> M;
    int package = INF, unit = INF;
    for(int i = 0; i < M; i++) {
        int P, U; cin >> P >> U;
        package = min(package, P);
        unit = min(unit, U);
    }
    int ans = 0;
    if(6 * unit < package) {
        ans = N * unit;
        N = 0;
    }
    else {
        ans += ((N / 6) * package);
        N %= 6;
    }
    ans += min(N * unit, package);
    
    cout << ans;
}