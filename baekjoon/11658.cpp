#include <bits/stdc++.h>

using namespace std;

const int MN = 1025;
int arr[MN][MN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            arr[i][j] += arr[i][j-1];
        }
    }

    while(M--) {
        int w, x1, x2, y1, y2, c; cin >> w;
        if(w == 0) {
            cin >> x1 >> y1 >> c;
            int gap = c - (arr[x1][y1] - arr[x1][y1-1]);
            for(int i = y1; i <= N; i++) {
                arr[x1][i] += gap;
            }
        }
        else {
            cin >> x1 >> y1 >> x2 >> y2;
            int ans = 0;
            for(int i = x1; i <= x2; i++) {
                ans += arr[i][y2] - arr[i][y1 - 1];
            }
            cout << ans << '\n';
        }
    }
}