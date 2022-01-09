#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MN = 100001;
int before[MN];

void print(int n) {
    if(before[n] == n) {
        cout << n <<' ';
        return;
    }
    print(before[n]);
    cout << n << ' ';
    return;
}

int main() {
    int N, K; cin >> N >> K;
    memset(before, -1, sizeof(before));
    queue<pair<int,int>> q;
    before[N] = N;
    if(N != K)
        q.push({N, 0});
    int ans = 0;
    while(!q.empty()) {
        pair<int,int> now = q.front(); q.pop();
        int nxt;
        nxt = now.first * 2;
        if(nxt == K) {
            ans = now.second + 1;
            before[K] = now.first;
            break;
        }
        if(nxt >= 0 && nxt < MN) {
            if(before[nxt] == -1) {
                before[nxt] = now.first;
                q.push({nxt, now.second + 1});
            }
        }
        nxt = now.first - 1;
        if(nxt == K) {
            ans = now.second + 1;
            before[K] = now.first;
            break;
        }
        if(nxt >= 0 && nxt < MN) {
            if(before[nxt] == -1) {
                before[nxt] = now.first;
                q.push({nxt, now.second + 1});
            }
        }
        nxt = now.first + 1;
        if(nxt == K) {
            ans = now.second + 1;
            before[K] = now.first;
            break;
        }
        if(nxt >= 0 && nxt < MN) {
            if(before[nxt] == -1) {
                before[nxt] = now.first;
                q.push({nxt, now.second + 1});
            }
        }
    }
    cout << ans << '\n';
    print(K);
}