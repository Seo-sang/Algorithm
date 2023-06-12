#include <bits/stdc++.h>

using namespace std;
const int MN = 21;
int arr[MN][MN];
int N;
int sum(int now) {
    int ret = 0;
    for(int i = 0; i < N; i++) {
        if((now & (1 << i)) == 0) continue;
        for(int j = i + 1; j < N; j++) {
            if((now & (1 << j)) == 0) continue;
            ret += arr[i][j] + arr[j][i];
        }
    }

    return ret;
}

int main() {
    cin >> N;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> arr[i][j];
    
    int ans = 1e9;
    for(int i = 1; i < (1 << N) - 1; i++) {
        int start = sum(i);
        int link = sum(~i);
        ans = min(ans, abs(start - link));
    }

    cout << ans;
}