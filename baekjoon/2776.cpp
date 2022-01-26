#include <bits/stdc++.h>

using namespace std;
const int MN = 1e6 + 1;
int arr[MN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        for(int i = 0; i < N; i++)
            cin >> arr[i];

        sort(arr, arr + N);
        int M; cin >> M;
        while(M--) {
            int a; cin >> a;
            cout << binary_search(arr, arr + N, a) << '\n';
        }
    }
}