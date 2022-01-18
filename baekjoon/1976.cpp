#include <bits/stdc++.h>

using namespace std;
const int MN = 201;
int p[MN];

void init(int n) {
    for(int i = 1; i <= n; i++)
        p[i] = i;
}

int find(int n) {
    if(n == p[n]) return n;
    return p[n] = find(p[n]);
}

int main() {
    int N, M; cin >> N >> M;
    init(N);
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            int a; cin >> a;
            if(a == 1) {
                if(find(i) != find(j))
                    p[find(i)] = j;
            }
        }
    }

    int s; cin >> s;
    M--;
    string ans = "YES";
    while(M--) {
        int a; cin >> a;
        if(find(s) != find(a)) 
            ans = "NO";
    }
    cout << ans;

}