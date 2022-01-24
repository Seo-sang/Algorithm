#include <bits/stdc++.h>

using namespace std;
const int MN = 1001;
const int mod = 1e9 + 7;
long long arr[MN][MN];

int main() {
    int N, M; cin >> N >> M;

    for(int i = 1; i <= N; i++)
        arr[i][1] = 1;

    for(int j = 1; j <= M; j++)
        arr[1][j] = 1;

    for(int i = 2; i <= N; i++)
        for(int j = 2; j <= M; j++)
            arr[i][j] = (arr[i-1][j] + arr[i][j-1] + arr[i-1][j-1]) % mod;

    cout << arr[N][M];
}