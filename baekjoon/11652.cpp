#include <iostream>
#include <map>

using namespace std;

map<long long, int> m;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    long long ans; cin >> ans;
    m[ans]++;
    N--;
    while(N--) {
        long long a; cin >> a;
        m[a]++;
        if(m[ans] < m[a]) ans = a;
        else if(m[ans] == m[a]) ans = min(ans, a);
    }

    cout << ans;
}