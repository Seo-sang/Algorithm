#include <bits/stdc++.h>

using namespace std;

const int MN = 262144;

vector<int> g[MN];

long long h[MN];
long long fruit[MN];
void dfs(int n, int prev){
    for(int next : g[n]) {
        if(next == prev) continue;
        
        h[next] = h[n] + fruit[next];
        dfs(next, n);
    }
}

int main(void){
    int N;  cin >> N;


    if(N % 2) {
        for(int i = 1; i <= N/2; i++) {
            int tmp = i*2;
            g[i].push_back(tmp);
            g[tmp].push_back(i);
            g[i].push_back(tmp + 1);
            g[tmp + 1].push_back(i);
        }
    }
    else {
        for(int i = 1; i <= (N/2 - 1); i++) {
            int tmp = i*2;
            g[i].push_back(tmp);
            g[tmp].push_back(i);
            g[i].push_back(i*2 + 1);
            g[tmp + 1].push_back(i); 
        }
        g[N/2].push_back(N);
        g[N].push_back(N/2);
    }
    for(int i = 1; i <= N; i++) {
        cin >> fruit[i];
    }
    int q; cin >> q;
    for(int i = 0; i <= q; i++) {
        if(i != 0) {
            int a, b; cin >> a, b;
            fruit[a] = b;
        }
        h[1] = fruit[1];
        dfs(1, 0);

        long long mx = 1;

        for(int i = 1; i <= N; i++)
            if(h[mx] < h[i])
                mx = i;
        memset(h, 0, sizeof(h));
        h[mx] = fruit[mx];
        
        dfs(mx, 0);
        long long my = 1;
        for(int i = 1; i <= N; i++)
            if(h[my] < h[i])
                my = i;
        if(mx < my) cout << h[my] <<'\n';
        else cout << h[my] <<'\n';
    }
}