#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

const int MN = 10000;
int s[MN];
bool visit[MN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    for(int i = 2; i * i < MN; i++) {
        if(s[i]) continue;
        for(int j = i * 2; j < MN; j += i) {
            s[j] = true;
        }
    }
    while(T--) {
        int ans = -1;
        memset(visit, 0, sizeof(visit));
        int dept, dest; cin >> dept >> dest;
        if(dept == dest) {
            cout << 0 << '\n';
            continue;
        }
        visit[dept] = true;
        queue<pair<int,int>> q;
        q.push({dept, 0});
        while(!q.empty() && ans == -1) {
            pair<int,int> now = q.front(); q.pop();
            int d[4];
            d[3] = now.first / 1000;
            now.first %= 1000;
            d[2] = now.first / 100;
            now.first %= 100;
            d[1] = now.first / 10;
            now.first %= 10;
            d[0] = now.first;
            int sum;
            for(int i = 0; i < 4; i++) {
                for(int j = 0; j < 10; j++) {
                    sum = 0;
                    for(int k = 0; k < 4; k++) {
                        if(i == k) {
                            sum += (j * pow(10, k));
                        }
                        else
                            sum += (d[k] * pow(10, k));
                    }
                    if(sum < 1000 || sum > 9999 || s[sum] || visit[sum]) continue;
                    if(sum == dest) {
                        ans = now.second + 1;
                        break;
                    }
                    visit[sum] = true;
                    //cout << sum << ' ' << now.second + 1 << endl;
                    q.push({sum, now.second + 1});
                }
            }
        }
        if(ans == -1)
            cout << "Impossible\n";
        else
            cout << ans << '\n';
    }
}