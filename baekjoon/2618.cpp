#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF = 1e9;
const int MN = 1003;
int N, W;
int dp[MN][MN];
pair<int,int> crim[MN];


int dist(pair<int,int> a, pair<int,int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int dfs(int one, int two, int n) {
    if(one == W + 2 || two == W + 2) return 0;
    if(dp[one][two] != INF) return dp[one][two];

    int d1 = dist(crim[one], crim[n]);
    int d2 = dist(crim[two], crim[n]);
    //1번이 간 경우
    int dist1 = dfs(n, two, n + 1) + d1;
    //2번이 간 경우
    int dist2 = dfs(one, n, n + 1) + d2;
    return dp[one][two] = min(dist1, dist2);
}

void trace(int one, int two) {
    if(one == W + 2 || two == W + 2) return;
    int next = max(one, two) + 1;
    int d1 = dist(crim[one], crim[next]);
    int d2 = dist(crim[two], crim[next]);
    if(dp[one][next] + d2 < dp[next][two] + d1) {
        cout << "2\n";
        trace(one, next);
    }
    else {
        cout << "1\n";
        trace(next, two);
    }

    return;
}

int main() {
    cin >> N >> W;
    fill(&dp[1][1], &dp[W+2][W+3], INF);

    crim[1].first = crim[1].second = 1;
    crim[2].first = crim[2].second = N;

    for(int i = 3; i <= W + 2; i++)
        cin >> crim[i].first >> crim[i].second;

    cout << dfs(1, 2, 3) << '\n';
    trace(1, 2);
}