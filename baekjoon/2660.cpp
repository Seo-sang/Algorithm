#include <bits/stdc++.h>

using namespace std;
const int MN = 51;
const int INF = 1e9;

int floyd[MN][MN];

int main() {
    int N; cin >> N;
    int a, b;
    fill(&floyd[0][0], &floyd[N][N+1], INF);
    for(int i = 1; i <= N; i++)
        floyd[i][i] = 0;
    while(true) {
        cin >> a >> b;
        if(a == -1 && b == -1) break;
        floyd[a][b] = 1;
        floyd[b][a] = 1;
    }

    for(int k = 1; k <= N; k++)
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);

    int ans = INF;
    vector<int> candidate;
    for(int i = 1; i <= N; i++) {
        int cnt = 0;
        for(int j = 1; j <= N; j++) 
            cnt = max(cnt, floyd[i][j]);
        if(ans > cnt) {
            ans = cnt;
            candidate.clear();
            candidate.push_back(i);
        }
        else if(ans == cnt)
            candidate.push_back(i);
    }

    cout << ans << ' ' << candidate.size() << '\n';
    for(int c : candidate)
        cout << c << ' ';
}