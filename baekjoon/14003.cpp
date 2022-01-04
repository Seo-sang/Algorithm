#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MN = 1000001;
const int INF = 1e9;
vector<int> dp;
vector<int> ans;
int pos[MN];
int arr[MN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;

    dp.push_back(-INF - 1);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        if(dp.back() < arr[i]) {
            dp.push_back(arr[i]);
            pos[i] = dp.size() - 1;
        }
        else {
            auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
            *it = arr[i];
            pos[i] = it - dp.begin();
        }
    }

    int s = dp.size() - 1;
    for(int i = N-1; i >= 0; i--) {
        if(pos[i] == s) {
            s--;
            ans.push_back(arr[i]);
        }
    }
    reverse(ans.begin(), ans.end());

    cout << dp.size() - 1 << '\n';
    for(int e : ans)
        cout << e << ' ';
}