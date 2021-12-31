#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct e {
    int num;
    int cnt;
};
int N; 

int p[1000002];
const int INF = 1e9;

int find(int n) {
    if(n == N) {
        cout << N << ' ';
        return 1;
    }
    if(n * 3 <= N  && p[n] == p[n * 3] + 1) {
        if(find(n * 3)) {
            cout << n << ' ';
            return 1;
        }
    }
    if(n * 2 <= N  && p[n]== p[n * 2] + 1) {
        if(find(n * 2)) {
            cout << n << ' ';
            return 1;
        }
    }
    if(n +1 <= N  && p[n] == p[n + 1] + 1) {
        if(find(n + 1)) {
            cout << n << ' ';
            return 1;
        }
    }

    return 0;
}

int main() {
    cin >> N;
    if(N == 1) {
        cout << 0 << '\n' << 1;
        return 0;
    }
    queue<e> q;
    fill(p, p + N + 1, INF);
    p[N] = 0;
    q.push({N, 0});
    int ans;
    while(!q.empty()) {
        e now = q.front(); q.pop();
        int num;
        num = now.num - 1;
        if(p[num] == INF) {
            q.push({num, now.cnt+1});
            p[num] = min(p[num], now.cnt+1);
            if(num == 1) {
                ans = now.cnt;
                break;
            }
        }

        if((now.num % 3) == 0 && p[now.num / 3] == INF) {
            num = now.num / 3;
            q.push({num, now.cnt+1});
            p[num] = min(p[num], now.cnt+1);
            if(num == 1) {
                ans = now.cnt;
                break;
            }
        }
        
        if((now.num % 2) == 0&& p[now.num / 2] == INF) {
            num = now.num / 2;
            q.push({num, now.cnt+1});
            p[num] = min(p[num], now.cnt+1);
            if(num == 1) {
                ans = now.cnt;
                break;
            }
        }
    }
    cout << ans + 1 << '\n';
    find(1);
}