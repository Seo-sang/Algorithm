#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MN = 100001;
int visit[MN];
int N, K;

int main() {
    memset(visit, -1, sizeof(visit));
    cin >> N >> K;
    if(N == K) {
        cout << 0;
        return 0;
    }
    visit[N] = true;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, N});
    while(!pq.empty()) {
        pair<int,int> now = pq.top(); pq.pop();
        int num = now.second;
        int score = now.first;
        int nxt;
        nxt = 2 * now.second;
        if(nxt == K) {
            cout << score;
            return 0;
        }
        if(nxt >= 0 && nxt < MN) {
            if(visit[nxt] == -1 || score < visit[nxt]) {
                visit[nxt] = score;
                pq.push({score, nxt});
            }
        }
        nxt = now.second - 1;
        if(nxt == K) {
            cout << score + 1;
            return 0;
        }
        if(nxt >= 0 && nxt < MN) {
            if(visit[nxt] == -1 || score + 1 < visit[nxt]) {
                visit[nxt] = score + 1;
                pq.push({score + 1, nxt});
            }
        }
        nxt = now.second + 1;
        if(nxt == K) {
            cout << score + 1;
            return 0;
        }
        if(nxt >= 0 && nxt < MN) {
            if(visit[nxt] == -1 || score + 1 < visit[nxt]) {
                visit[nxt] = score + 1;
                pq.push({score + 1, nxt});
            }
        }
    }
}