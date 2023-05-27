#include <bits/stdc++.h>

using namespace std;

const int MN = 26;

struct node {
    int start, end, num;
    node(int a, int b, int c) : start(a), end(b), num(c) {}
};

vector<node> arr;
int dp[MN][2];

int main() {
    int N; cin >> N;
    arr.push_back(node(0, 0, 0));
    for(int i = 0; i < N; i++) {
        int a, b, c; cin >> a >> b >> c;
        arr.push_back(node(a, b, c));
    }

    for(int i = 1; i <= N; i++) {
        node now = arr[i];
        dp[i][1] = dp[i-1][0] + now.num;

        if(arr[i].start == arr[i-1].end)
            dp[i][1] = max(dp[i][1], dp[i-1][1] + now.num);
        
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
    }

    cout << max(dp[N][0], dp[N][1]);
}