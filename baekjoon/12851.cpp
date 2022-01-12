#include <iostream>
#include <queue>

using namespace std;
const int MN = 100001;
const int INF = 1e9;

int pos[MN];
int visit[MN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, K; cin >> N >> K;
    fill(&visit[0], &visit[MN], INF);
    visit[N] = 0;
    queue<int> q;
    q.push(N);
    int mnum = INF;
    int ans = 0;
    if(N == K) {
        cout << 0 << '\n' << 1;
        return 0;
    }
    while(!q.empty()) {
        int now= q.front(); q.pop();

        int nxt = now * 2;
        if(nxt >= 0 && nxt < MN && visit[nxt] >= visit[now] + 1) {
            visit[nxt] = visit[now] + 1;
            q.push(nxt);
            if(nxt == K) {
                if(visit[now] + 1 < mnum) {
                    ans = 1;
                    mnum = visit[now] + 1;
                }
                else if(visit[now] + 1 == mnum)
                    ans++;
            }
        }

        nxt = now - 1;
        if(nxt >= 0 && nxt < MN && visit[nxt] >= visit[now] + 1) {
            visit[nxt] = visit[now] + 1;
            q.push(nxt);
            if(nxt == K) {
                if(visit[now] + 1 < mnum) {
                    ans = 1;
                    mnum = visit[now] + 1;
                }
                else if(visit[now] + 1 == mnum)
                    ans++;
            }
        }
        nxt = now + 1;
        if(nxt >= 0 && nxt < MN && visit[nxt] >= visit[now] + 1) {
            visit[nxt] = visit[now] + 1;
            q.push(nxt);
            if(nxt == K) {
                if(visit[now] + 1 < mnum) {
                    ans = 1;
                    mnum = visit[now] + 1;
                }
                else if(visit[now] + 1 == mnum)
                    ans++;
            }
        }
    }
    cout << mnum << '\n' << ans;
}