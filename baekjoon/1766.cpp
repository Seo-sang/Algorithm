#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

const int MN = 32001;
int child[MN];
vector<int> g[MN];

int N, M;

int main() {
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        child[b]++;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i =1; i <= N; i++)
        if(!child[i])
            pq.push(i);

    while(!pq.empty()) {
        int now = pq.top(); pq.pop();
        cout << now << ' ';
        for(int e : g[now]) {
            child[e]--;
            if(child[e] == 0)
                pq.push(e);
        }
    }
}