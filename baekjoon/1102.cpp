#include <bits/stdc++.h>
#define PP pair<int,int>

using namespace std;
const int MN = 17;
int g[MN][MN];

int main() {
    int N; cin >> N;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> g[i][j];

    string onoff; cin >> onoff;
    int P; cin >> P;
    int on = 0;
    priority_queue<PP, vector<PP>, greater<PP> > pq;

    for(int i = 0; i < N; i++) {
        if(onoff[i] == 'Y') {
            on++;
            for(int j = 0; j < N; j++) {
                if(onoff[j] == 'Y') continue;
                pq.push(make_pair(g[i][j], j));
            }
        }
    }
    int ans = 0;
    while(!pq.empty() && on < P) {
        PP now = pq.top(); pq.pop();
        if(onoff[now.second] == 'Y') continue;
        cout << now.second << ' ' << now.first << endl;
        onoff[now.second] = 'Y';
        on++;
        ans += now.first;
        for(int i = 0; i < N; i++) {
            if(onoff[i] == 'Y') continue;
            pq.push(make_pair(g[now.second][i], i));
        }
    }
    if(on < P) cout << -1;
    else cout << ans;
}