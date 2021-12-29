#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> dp;
vector<int> s;
int arr[1001];
int main() {
    int N; cin >> N;
    vector<int> ans;
    dp.push_back(-1);
    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        s.push_back(a);
        if(dp.back() < a) {
            dp.push_back(a);
            arr[i] = dp.size() - 1;
        }
        else {
            auto it = lower_bound(dp.begin(), dp.end(), a);
            *it = a;
            arr[i] = it - dp.begin();
        }
    }
    int now = dp.size()-1;
    for(int i = N-1; i >= 0; i--) {
        if(arr[i] == now) {
            ans.push_back(s[i]);
            now--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << dp.size() - 1 << '\n';
    for(int e : ans)
        cout << e << ' ';
}