#include <bits/stdc++.h>

using namespace std;

const int MN = 201;
const int MK = 21;
const int INF = 1e9;

int dp[MN][MK];
vector<int> arr;

int dfs(int n, int k, vector<int> &arr) {

    //left
    for(int i = n; i >= 0; i--) {
        
    }

    //right
}

int main() {
    int N, K; cin >> N >> K;

    
    fill(&dp[0][0], &dp[N-1][K], INF);

    for(int i =0;  i < N; i++) {
        int a; cin >> a;
        arr.push_back(a);
        dp[i][a] = 0;
    }

    for(int i = 0; i < N; i++) {
        if(i > 0 && arr[i] != arr[i - 1]) {
            dp[i - 1][arr[i]] = 1;
            dfs(i - 1, arr[i]);
        }
        if(i < N -1 && arr[i] != arr[i + 1]){
            dp[i + 1][arr[i]][1] = 1;
            dfs(i + 1, arr[i], 1);
        }
    }



}