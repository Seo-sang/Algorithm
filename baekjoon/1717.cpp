#include <iostream>

using namespace std;
const int MN = 1000001;

int p[MN];

int find(int n) {
    if(p[n] == n) return n;
    else return p[n] = find(p[n]);
}

void init(int n) {
    for(int i = 1; i <= n; i++)
        p[i] = i;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    init(N);

    while(M--) {
        int is, a, b; cin >> is >> a >> b;
        if(is == 0) {
            if(find(a) != find(b))
                p[find(a)] = b;
        }
        else {
            if(find(a) == find(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}