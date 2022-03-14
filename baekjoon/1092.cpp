#include <bits/stdc++.h>

using namespace std;
const int MN = 51;
const int MM = 10001;
int arr[MN];
int box[MM];

int main() {
    int N, M; cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N);
    cin >> M;
    int idx = 0;
    for(int i = 0; i < M; i++)
        cin >> box[i];
    for(int i = 0; i < M; i++) {
        int j;
        for(j = 0; j < N; j++) {
            
        }
        if(j == N) {
            cout << -1;
            return 0;
        }
    }
}