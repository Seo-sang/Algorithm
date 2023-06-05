#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

vector<pii> arr, st;


int main() {
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        arr.push_back(pii(a, b));
    }

    sort(arr.begin(), arr.end());
    st.push_back(arr[0]);
    int ans = 0;
    for(int i = 1; i < N; i++) {
        if(st.back().second < arr[i].second) {
            ans += (arr[i].first - st.back().first) * st.back().second;
            st.push_back(arr[i]);
        }
    }
    int idx = st.back().first;

    st.clear();
    st.push_back(arr[N-1]);
    for(int i = N-2; i >= 0; i--) {
        if(st.back().second < arr[i].second) {
            ans += (st.back().first - arr[i].first) * st.back().second;
            st.push_back(arr[i]);
        }
    }

    ans += (st.back().first - idx + 1) * st.back().second;

    cout << ans;
}