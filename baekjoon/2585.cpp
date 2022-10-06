#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;
const int MN = 1001;
vector<P> arr;
vector<P> g[MN];
int N, K;
bool vst[MN];

int dist(P a, P b) {
    int d1 = a.first - b.first;
    int d2 = a.second - b.second;
    d1 *= d1;
    d2 *= d2;
    double rst = (double)sqrt(d1 + d2);
    int tmp = rst;
    if((double)tmp == rst) return tmp / 10;
    else return tmp / 10 + 1;
}

int f(int mid) {
    queue<P> q; q.push(make_pair(0, 0));
    memset(vst, 0, sizeof(vst));
    vst[0] = true;

    while(!q.empty()) {
        P now = q.front(); q.pop();
        for(P nxt : g[now.second]) {
            if(nxt.first > mid || vst[nxt.second]) continue;
            if(nxt.second == N + 1) return now.first + 1;
            vst[nxt.second] = true;
            q.push(make_pair(now.first + 1, nxt.second));
        }
    }

    return 1e9;
}

int main() {
    cin >> N >> K;
    K++;
    for(int i = 1; i <= N; i++) {
        int x, y; cin >> x >> y;
        for(int j = 0; j < arr.size(); j++) {
            int d = dist(make_pair(x, y), arr[j]);
            g[i].push_back(make_pair(d, j + 1));
            g[j + 1].push_back(make_pair(d, i));
        }
        g[0].push_back(make_pair(dist(make_pair(0, 0), make_pair(x, y)), i));
        g[i].push_back(make_pair(dist(make_pair(x, y), make_pair(10000, 10000)), N + 1));
        arr.push_back(make_pair(x, y));
    }

    int left = 0, right = 20000;
    while(left + 1 < right) {
        int mid = (left + right) / 2;
        int rst = f(mid);
        if(rst <= K)right = mid;
        else left = mid;
    }
    
    cout << right;
}