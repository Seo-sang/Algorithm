#include <bits/stdc++.h>

using namespace std;
const int MN = 101;
int arr[MN];
bool vst[MN];

int main() {
    int N, K; cin >> N >> K;
    vector<int> v;
    for(int i = 0; i < K; i++)
        cin >> arr[i];

    int ans = 0;
    for(int i = 0; i < K; i++) {
        if(find(v.begin(), v.end(), arr[i]) == v.end()) {
            if(v.size() < N) v.push_back(arr[i]);
            else {
                ans++;
                int cnt = 0;
                memset(vst, 0, sizeof(vst));
                for(int j = i + 1; j < K; j++) {
                    if(cnt == N - 1) break;
                    auto it = find(v.begin(), v.end(), arr[j]);
                    if(it == v.end()) continue;
                    int idx = it - v.begin();
                    if(!vst[idx]) cnt++;
                    vst[idx] = true;
                }
                for(int j = 0; j < N; j++) {
                    if(!vst[j]) {
                        v[j] = arr[i];
                        break;
                    }
                }
            }
        }
    }

    cout << ans;
}