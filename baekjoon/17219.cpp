#include <bits/stdc++.h>

using namespace std;
map<string,string> m;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    for(int i = 0; i < N; i++) {
        string url, pw; cin >> url >> pw;
        m[url] = pw;
    }
    while(M--) {
        string url; cin >> url;
        cout << m[url] << '\n';
    }
}