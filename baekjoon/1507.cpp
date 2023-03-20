#include <bits/stdc++.h>

using namespace std;

const int MN = 21;
const int INF = 1e9;
int floyd[MN][MN];
int arr[MN][MN];

struct node {
    int a, b, w;
    node(int a, int b, int w) : a(a), b(b), w(w) {}
};

bool cmp(node a, node b) {
    return a.w < b.w;
}

int main() {
    int N; cin >> N;
    int ans = 0;
    vector<node> edge;

    fill(&floyd[0][0], &floyd[N][N + 1], INF);
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            cin >> arr[i][j];

    for(int i = 1; i <= N; i++) {
        floyd[i][i] = 0;
        for(int j = i + 1; j <= N; j++) {
            edge.push_back(node(i, j, arr[i][j]));
        }
    }

    sort(edge.begin(), edge.end(), cmp);

    for(node e : edge) {
        if(floyd[e.a][e.b] > arr[e.a][e.b]) {
            floyd[e.a][e.b] = arr[e.a][e.b];
            floyd[e.b][e.a] = arr[e.b][e.a];
            ans += arr[e.a][e.b];
        }

        for(int k = 1; k <= N; k++)
            for(int i = 1; i <= N; i++)
                for(int j = 1; j <= N; j++)
                    floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
    }

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            if(floyd[i][j] < arr[i][j]) ans = INF;

    if(ans == INF) cout << -1;
    else cout << ans;
}