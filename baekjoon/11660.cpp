#include <iostream>

using namespace std;

int arr[1025][1025];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        int rowsum = 0;
        for(int j = 1; j <= N; j++) {
            int a; cin >> a;
            rowsum += a;
            arr[i][j] = arr[i-1][j] + rowsum;
        }
    }
    
    while(M--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << arr[c][d] - arr[c][b-1] - arr[a-1][d] + arr[a-1][b-1] << '\n';
    }
}