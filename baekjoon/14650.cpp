#include <bits/stdc++.h>

using namespace std;

const int MN = 10;
int N;
int dfs(int n, int now, int sum) {
    if(n == N) {
        if(sum % 3) return 0;
        else return 1;
    }
    return dfs(n + 1, 0, sum) + dfs(n + 1, 1, sum + 1) + dfs(n + 1, 2, sum + 2);
}

int main() {
    cin >> N;
    cout << dfs(1, 1, 1) + dfs(1, 2, 2);
}