#include <iostream>
#include <queue>
#include <algorithm>
#include <set>

#define P pair<int,int>

using namespace std;


const int MN = 300001;
pair<int,int> MV[MN];
int C[MN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, K; cin >> N >> K;
    priority_queue<int, vector<int>, less<int>> pq;
    for(int i = 0; i < N; i++)
        cin >> MV[i].first >> MV[i].second;

    for(int i = 0; i < K; i++) 
        cin >> C[i];

    sort(MV, MV + N);
    sort(C, C + K);
    
    long long ans = 0;
    int idx = 0;
    for(int i = 0; i < K; i++) {
        while(idx < N && C[i] >= MV[idx].first) {
            pq.push(MV[idx].second);
            idx++;
        }
        if(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;
}