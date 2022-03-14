#include <bits/stdc++.h>

using namespace std;
const int MN = 10001;
int arr[MN];
vector<int> gap;
int N, K;

int main() {
    cin >> N >> K;
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N);
    for(int i = 1; i < N; i++)
        gap.push_back(arr[i] - arr[i-1]);
    sort(gap.begin(), gap.end());
    if(N < K) K = N;
    K--;
    while(K--)
        gap.pop_back();
    int ans = 0;
    for(int e : gap)
        ans += e;
    cout << ans;
}
