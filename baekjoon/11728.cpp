#include <bits/stdc++.h>

using namespace std;

const int MN = 1000001;
int A[MN], B[MN], ans[MN * 2];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];

    int a, b = 0;
    while(a < N && b < M) {
        if(A[a] <= B[b]) {
            ans[a + b] = A[a];
            a++;
        }
        else {
            ans[a + b] = B[b];
            b++;
        }
    }

    while(a < N) {
        ans[a + b] = A[a];
        a++;
    }
    while(b < M) {
        ans[a + b] = B[b];
        b++;
    }

    for(int i = 0; i < N + M; i++)
        cout << ans[i] << ' ';
}