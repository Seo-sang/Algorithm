#include <bits/stdc++.h>

using namespace std;
const int MN = 100001;
int dp[MN][5][5];
vector<int> arr;

int cost(int now, int nxt) {
    switch(now) {
        case 0:
            switch(nxt) {
                case 1: return 2;
                case 2: return 2;
                case 3: return 2;
                case 4: return 2;
            }
            break;
        case 1:
            switch(nxt) {
                case 1: return 1;
                case 2: return 3;
                case 3: return 4;
                case 4: return 3;
            }
            break;
        case 2:
            switch(nxt) {
                case 1: return 3;
                case 2: return 1;
                case 3: return 3;
                case 4: return 4;
            }
            break;
        case 3:
            switch(nxt) {
                case 1: return 4;
                case 2: return 3;
                case 3: return 1;
                case 4: return 3;
            }
            break;
        case 4:
            switch(nxt) {
                case 1: return 3;
                case 2: return 4;
                case 3: return 3;
                case 4: return 1;
            }
            break;
    }
    return 0;
}

int dfs(int n, int left, int right) {
    if(n + 1 == arr.size()) return 0;
    int &ret = dp[n][left][right];
    if(ret != -1) return ret;
    //왼발이 가는 경우
    int c1 = cost(left, arr[n + 1]);
    //오른발이 가는 경우
    int c2 = cost(right, arr[n+ 1]);
    ret = min(dfs(n + 1, arr[n+1], right) + c1, dfs(n+1, left, arr[n+1]) + c2);
    return ret;
}

int main() {
    int n; 
    arr.push_back(0);
    while(true) {
        cin >> n;
        if(n == 0) break;
        arr.push_back(n);
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 0, 0);
}