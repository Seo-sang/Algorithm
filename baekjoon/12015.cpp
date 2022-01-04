#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dp;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    dp.push_back(-1);

    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        if(dp.back() < a) dp.push_back(a);
        else {
            auto it = lower_bound(dp.begin(), dp.end(), a);
            *it = a;
        }
    }

    cout << dp.size() - 1;
}