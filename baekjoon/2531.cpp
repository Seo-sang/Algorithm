#include <bits/stdc++.h>

using namespace std;

const int MN = 30001;
int arr[MN];
map<int,int> m;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, D, K, C; cin >> N >> D >> K >> C;
    m[C]++;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        if(i < K) m[arr[i]]++;
    }

    int ans = m.size();
    int left, right = K % N;

    for(left = 1; left < N; left++) {
        m[arr[left-1]]--;
        m[arr[right]]++;
        if(m[arr[left-1]] == 0) m.erase(arr[left-1]);
        right = (right + 1) % N;

        ans = max(ans, (int)m.size());
    }

    cout << ans;

}