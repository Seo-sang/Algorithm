#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
const int MN = 1025;
int arr[MN];
vector<int> pos[MN];

void dfs(int left, int right, int level) {
    int mid = (left + right) / 2;
    if(left > right) return;
    pos[level].push_back(arr[mid]);
    dfs(left, mid - 1, level + 1);
    dfs(mid + 1, right, level + 1);
}

int main() {
    int K; cin >> K;
    for(int i = 1; i <= pow(2, K) - 1; i++) {
        cin >> arr[i];
    }
    dfs(1, pow(2, K) - 1, 1);

    for(int i = 1; i <= K; i++) {
        for(int e : pos[i])
            cout << e << ' ';
        cout << '\n';
    }
}