#include <bits/stdc++.h>

using namespace std;

const int MN = 100001;

struct node {
    int start, end, num;
    node(int a, int b, int c) : start(a), end(b), num(c) {}
};

bool cmp(node a, node b) {
    return (a.start < b.start) || (a.start == b.start && a.end < b.end);
}

vector<node> arr;
vector<int> v;  //압축 좌표
set<int> st;
int dp[MN * 2];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        int a, b, c; cin >> a >> b >> c;
        arr.push_back(node(a, b, c));
        v.push_back(a);
        v.push_back(b);
    }

    sort(arr.begin(), arr.end(), cmp);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    st.insert(0);

    int ans = 0;
    for(int i = 0; i < N; i++) {
        int start, end ,num;
        start = lower_bound(v.begin(), v.end(), arr[i].start) - v.begin();
        end = lower_bound(v.begin(), v.end(), arr[i].end) - v.begin();
        num = arr[i].num;
        auto it = upper_bound(st.begin(), st.end(), start);
        it--;
        dp[end] = max(dp[end], dp[*it] + num);
        ans = max(ans, dp[end]);
        st.insert(end);
    }

    cout << ans;
}