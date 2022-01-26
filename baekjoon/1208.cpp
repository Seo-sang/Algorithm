#include <bits/stdc++.h>

using namespace std;
const int MN = 41;
int arr[MN];

int v1[1 << 21];
int v2[1 << 21];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, S; cin >> N >> S;

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    int front = N / 2;
    int back = N - front;

    for(int i = 0; i < front; i++) {
        for(int j = 0; j < (1 << i); j++) {
            v1[(1 << i) | j] = v1[j] + arr[i];
        }
    }
    for(int i = 0; i < back; i++) {
        for(int j = 0 ; j < (1 << i); j++) {
            v2[(1 << i) | j] = v2[j] + arr[i + front];
        }
    }
    sort(&v2[0], &v2[1 << back]);
    long long ans = 0;
    for(int i = 0; i < (1 << front); i++) {
        auto it1 = lower_bound(&v2[0], &v2[1 << back], S - v1[i]);
        auto it2 = upper_bound(&v2[0], &v2[1 << back], S - v1[i]);
        ans += (it2 - it1);
    }
    
    if(S == 0) ans--;
    cout << ans;
}