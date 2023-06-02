#include <bits/stdc++.h>

using namespace std;

queue<int> q;
vector<int> arr;

int main() {
    int N, W, L; cin >> N >> W >> L;
    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        arr.push_back(a);
    }

    int ans = 0, sum = 0;
    for(int i = 0; i < N; i++) {
        if(sum + arr[i] > L || q.size() == W) {
            ans += W - q.size() + 1;
            sum -= q.front();
            q.pop();
        }
        sum += arr[i];
        q.push(arr[i]);
    }

    cout << ans;
}